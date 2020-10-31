uniform sampler2D LastPass;
uniform sampler2D DiffuseMap;
uniform sampler2D NormalMap;
uniform vec3 AmbientLight;
uniform int LightCount;
uniform int PassNumber;

struct LightInfo
{
	vec3 position;
	vec3 color;
	float radius;
	float falloff;
};
const int MaxLights = 3;
uniform LightInfo Lights[MaxLights];

void main()
{
	vec4 pixel = texture2D(LastPass, gl_TexCoord[0].xy);
	vec4 diffusepixel = texture2D(DiffuseMap, gl_TexCoord[0].xy);
	vec4 normalpixel = texture2D(NormalMap, gl_TexCoord[0].xy);
	vec3 PixelCoordinates = vec3(gl_FragCoord.x, gl_FragCoord.y, gl_FragCoord.z);
	vec4 finalPixel = (gl_Color * pixel);
	vec3 viewDirection = vec3(0,0,1);
	if (PassNumber == 1)
		finalPixel *= vec4(AmbientLight, 1.0);

	vec3 N = normalize(normalpixel.rgb * 2.0 - 1.0);

	for (int i = 0; i < LightCount; i++)
	{
		vec3 L = Lights[i].position - gl_FragCoord.xyz;
		float distance = length(L);
		float d = max(distance - Lights[i].radius, 0.0);
		L /= distance;

		float attenuation = 1.0 / pow(d/Lights[i].radius + 1, 2);
		attenuation = (attenuation - Lights[i].falloff) / (1.0 - Lights[i].falloff);
		attenuation = max(attenuation, 0.0);
		float normalDot = max(dot(N,L), 0.0);
		finalPixel += (diffusepixel * ((vec4(Lights[i].color, 1.0) * attenuation))) * normalDot;
	}
	gl_FragColor = finalPixel;
}