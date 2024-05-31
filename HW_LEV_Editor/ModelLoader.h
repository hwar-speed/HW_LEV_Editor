#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include <Files.h>

#include <Vectors.h>
#include <Object.h>

using namespace std;

struct Vert
{
	Vector3 pos;
	Vector2 uv;
	Vector3 norm;
	// material index is a n=0-254 integer equal to the nth row of the .cfg texture list
	unsigned char mat_index;

	// mat_index is an optional arg, defaults to 255 (255 means do not update, retain existing material index)
	Vert() : mat_index(255) {} 
	Vert(Vector3 pos, Vector2 uv, Vector3 norm, unsigned char mat_index = 255)
	{
		this->pos = pos;
		this->uv = uv;
		this->norm = norm;
		this->mat_index = mat_index;
	}
};

struct StructMaterial
{
	string name;
	string texturePath;

	StructMaterial() {}
	StructMaterial(string name, string texturePath)
	{
		this->name = name;
		this->texturePath = texturePath;
	}
};

vector<ObjObject*> LoadModelsFromFile(string path);
