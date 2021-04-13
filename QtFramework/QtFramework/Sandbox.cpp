#include "Sandbox.h"

using namespace cagd;
using namespace std;

Sandbox::Sandbox()
{
}

GLvoid cagd::Sandbox::Init()
{
	baseImagesOfModels.ResizeColumns(18);
	baseImagesOfModels[0].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/angel.off", true);
	baseImagesOfModels[0].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[1].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/bird.off", true);
	baseImagesOfModels[1].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[2].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/bug.off", true);
	baseImagesOfModels[2].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[3].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/cone.off", true);
	baseImagesOfModels[3].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[4].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/cube.off", true);
	baseImagesOfModels[4].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[5].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/dragon.off", true);
	baseImagesOfModels[5].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[6].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/elephant.off", true);
	baseImagesOfModels[6].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[7].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/gangster.off", true);
	baseImagesOfModels[7].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[8].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/goblet.off", true);
	baseImagesOfModels[8].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[9].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/horse.off", true);
	baseImagesOfModels[9].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[10].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/icosahedron.off", true);
	baseImagesOfModels[10].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[11].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/Lucy.off", true);
	baseImagesOfModels[11].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[12].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/mouse.off", true);
	baseImagesOfModels[12].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[13].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/seashell.off", true);
	baseImagesOfModels[13].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[14].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/space_station.off", true);
	baseImagesOfModels[14].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[15].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/sphere.off", true);
	baseImagesOfModels[15].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[16].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/Spot.off", true);
	baseImagesOfModels[16].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
	baseImagesOfModels[17].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/star.off", true);
	baseImagesOfModels[17].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW);
}

GLboolean cagd::Sandbox::LoadFromFile(const string& file_name)
{
	fstream f(file_name.c_str(), ios_base::in);

	f >> numberOfModels;
	imagesOfModels.ResizeColumns(numberOfModels);
	materialsOfModels.ResizeColumns(numberOfModels);
	scales.ResizeColumns(numberOfModels);
	translations.ResizeColumns(numberOfModels);
	rotations.ResizeColumns(numberOfModels);
	modelIndexes.ResizeColumns(numberOfModels);
	effectScales.ResizeColumns(numberOfModels);
	effectTypes.ResizeColumns(numberOfModels);

	for (int i = 0; i < numberOfModels; i++)
	{
		GLuint materialIndex;
		f >> materialIndex;
		materialsOfModels[i] = Material::GetByIndex(materialIndex);
		f >> scales[i];
		f >> rotations[i];
		f >> translations[i];
		f >> effectTypes[i];
		f >> effectScales[i];
		f >> modelIndexes[i];

		imagesOfModels[i] = TriangulatedMesh3(baseImagesOfModels[modelIndexes[i]]);
		imagesOfModels[i].Rotate(rotations[i].x(), rotations[i].y(), rotations[i].z());
		imagesOfModels[i].Scale(scales[i]);
		imagesOfModels[i].Translate(translations[i].x(), translations[i].y(), translations[i].z());
		if (!imagesOfModels[i].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW))
		{
			cout << "Couldn't update Vertex Buffer Objects" << endl;
		}
	}

	f.close();

	return GL_TRUE;
}

GLboolean cagd::Sandbox::SaveToFile(const std::string& file_name)
{
	fstream f(file_name.c_str(), ios_base::out);

	f << numberOfModels << endl;

	for (int i = 0; i < numberOfModels; i++)
	{
		f << materialsOfModels[i].Index << endl;
		imagesOfModels[i].SaveToFstream(f);
	}

	return GL_TRUE;
}

GLvoid cagd::Sandbox::Render()
{
	for (int i = 0; i < numberOfModels; i++)
	{
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_NORMALIZE);
		materialsOfModels[i].Apply();
		imagesOfModels[i].Render();
		glDisable(GL_LIGHTING);
		glDisable(GL_NORMALIZE);
		glDisable(GL_LIGHT0);
	}
}

GLvoid cagd::Sandbox::Animate(GLfloat angle)
{
	RowMatrix<GLfloat*> vertices, normals;
	vertices.ResizeColumns(numberOfModels);
	normals.ResizeColumns(numberOfModels);
	for (int i = 0; i < numberOfModels; i++)
	{
		vertices[i] = imagesOfModels[i].MapVertexBuffer(GL_READ_WRITE);
		normals[i] = imagesOfModels[i].MapNormalBuffer(GL_READ_ONLY);
		GLfloat scale = 0.0;
		if (effectTypes[i] == 1)
		{
			scale = sin(angle) / effectScales[i];
		}
		if (effectTypes[i] == 2)
		{
			scale = cos(angle) / effectScales[i];
		}
		for (int j = 0; j < imagesOfModels[i].VertexCount(); j++)
		{
			for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertices[i], ++normals[i])
			{
				*vertices[i] += scale * (*normals[i]);
			}
		}

		imagesOfModels[i].UnmapVertexBuffer();
		imagesOfModels[i].UnmapNormalBuffer();
	}
}
