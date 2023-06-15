/*#pragma once
#include <GL/glew.h>
#include "Vertex.h"
#include <glm/glm.hpp>
#include <vector>
using namespace std;

enum class GlyphSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

class RenderBatch {
public:
	GLuint offset;
	GLuint numVertices;
	GLuint texture;
	RenderBatch(GLuint offset, GLuint num, GLuint texture) {
		this->numVertices = numVertices;
		this->offset = offset;
		this->texture = texture;
	}
};

struct Glyph {
	Glyph(){}
	Glyph(const glm::vec4& desRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color) {
		this->texture = texture;
		this->depth = depth;
		topLeft color
	}


	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomright;
};

class SpriteBatch
{
private:
	GLuint vbo;
	GLuint vba;
	vector<Glyph> glyphs;
	vector<Glyph*> glyphsPointers;
	vector<RenderBatch> renderBatch;
	GlyphSortType sortType;
	void init();
	void begin(GlyphSortType type);
	void end();
	void createRenderBatches();
	void createVertexArray();
	void sortGlyph();
public:
	SpriteBatch();
	~SpriteBatch();
	void renderBatch();
	void draw();
	bool compareFrontToBack(Glyph* a, Glyph* b);
	bool compareBackToFront(Glyph* a, Glyph* b);
	bool compareTexture(Glyph* a, Glyph* b);
};

*/