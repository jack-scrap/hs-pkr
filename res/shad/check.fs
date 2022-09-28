#version 400

in vec2 _pos;

uniform uint t;

vec3[2] grey = vec3[2](
	vec3(34, 34, 34),
	vec3(102, 102, 102)
);

vec3[2] purple = vec3[2](
	vec3(69, 59, 87),
	vec3(97, 82, 134)
);

const float stride = 1.0;

void main() {
	vec3[2] col = grey;
	if (bool(t)) {
		col = purple;
	}

	gl_FragColor = vec4(col[int(mod(_pos.x, stride * 2) > stride ^^ mod(_pos.y, stride * 2) > stride)] / 255.0, 1.0);
}
