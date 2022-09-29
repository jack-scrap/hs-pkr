#version 400

in vec2 pos;

out vec2 _pos;

uniform uvec2 res;
uniform mat4 model;

float ratio = float(res.x) / float(res.y);

void main() {
	gl_Position = vec4(vec2(model * vec4(vec2(pos.x / ratio, pos.y), 0.0, 1.0)) * vec2(0.1), 0.0, 1.0);

	_pos = pos;
}
