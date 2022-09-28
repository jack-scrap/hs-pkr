#version 400

uniform uint t;

vec3[2] grey = vec3[2](
	vec3(34, 34, 34),
	vec3(102, 102, 102)
);

vec3[2] purple = vec3[2](
	vec3(69, 59, 87),
	vec3(97, 82, 134)
);

void main() {
	vec3[2] col = grey;
	if (bool(t)) {
		col = purple;
	}

	gl_FragColor = vec4(col[int(false)] / 255.0, 1.0);
}
