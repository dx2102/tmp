#pragma once

#include "GL.hpp"

#include <glm/glm.hpp>

struct PixelCanvas {
	static constexpr uint32_t Width = 256, Height = 240;
	static constexpr float Aspect = float(Width) / float(Height);

	PixelCanvas() = default;
	PixelCanvas(PixelCanvas const &) = delete;
	~PixelCanvas();

	void begin(glm::vec3 const &background);
	void end(glm::uvec2 const &drawable_size);
	glm::vec2 from_window(glm::vec2 const &position, glm::uvec2 const &window_size) const;
	glm::mat4 world_to_clip() const;
	//world units to canvas pixels, (0,0) is the lower left pixel:
	glm::vec2 world_to_pixel(glm::vec2 const &world) const;
	//canvas pixels to drawable pixels, for drawing on top of the canvas after end():
	glm::vec2 pixel_to_drawable(glm::vec2 const &pixel, glm::uvec2 const &drawable_size) const;

	GLuint framebuffer = 0, texture = 0;
	glm::vec4 rect = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
};
