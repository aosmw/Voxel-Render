#ifndef SHADOW_VOLUME_H
#define SHADOW_VOLUME_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "vao.h"
#include "camera.h"
#include "shader.h"

#include "../lib/tinyxml2.h"
using namespace tinyxml2;

class ShadowVolume {
private:
	VAO vao;
	int width, height, depth, volume;
	GLuint volumeTexture;
	uint8_t* shadowVolume;

	XMLDocument scene_xml;
	XMLElement* scene_root = NULL;
public:
	ShadowVolume(float width_m, float height_m, float depth_m);
	void addShape(const MV_Shape& shape, mat4 model_matrix);
	void updateTexture();
	void draw(Shader& shader, Camera& camera);
	~ShadowVolume();
};

#endif
