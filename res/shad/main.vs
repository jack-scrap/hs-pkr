#version 400

in vec2 pos;

out vec2 _pos;

uniform uvec2 res;
uniform mat4 acc;

float ratio = float(res.x) / float(res.y);

void main() {
	gl_Position = vec4(vec2(acc * vec4(pos, 0.0, 1.0)) * vec2(0.1) * vec2(1 / ratio, 1), 0.0, 1.0);

	_pos = pos;
}
