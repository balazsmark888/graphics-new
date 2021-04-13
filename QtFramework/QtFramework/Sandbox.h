#pragma once
#include <Core/TriangulatedMeshes3.h>
#include <Core/Matrices.h>
#include <Core/Materials.h>
#include <string>
#include <iostream>
#include <GL/glew.h>

namespace cagd
{
	class Sandbox
	{
	public:
		Sandbox();
		GLvoid Init();
		int numberOfModels;
		RowMatrix<TriangulatedMesh3> imagesOfModels;
		RowMatrix<TriangulatedMesh3> baseImagesOfModels;
		RowMatrix<Material> materialsOfModels;
		RowMatrix<GLdouble> scales;
		RowMatrix<DCoordinate3> translations;
		RowMatrix<DCoordinate3>	rotations;
		RowMatrix<GLuint> effectTypes;
		RowMatrix<GLdouble> effectScales;
		RowMatrix<GLuint> modelIndexes;

		GLboolean LoadFromFile(const std::string& file_name);
		GLboolean SaveToFile(const std::string& file_name);
		GLvoid Render();
		GLvoid Animate(GLfloat angle);
	};

}


