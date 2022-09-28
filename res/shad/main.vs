#version 400

in vec2 pos;

out vec2 _pos;

uniform vec2 loc;
uniform uvec2 res;

float ratio = float(res.x) / float(res.y);

void main() {
	gl_Position = vec4((loc + vec2(pos.x / ratio, pos.y)) * vec2(0.1), 0.0, 1.0);

	_pos = pos;
}
