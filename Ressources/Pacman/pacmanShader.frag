uniform vec3 u_resolution;
uniform int u_frame;

#define M_PI 3.14159265358

void main()
{
    vec2 xy = (gl_FragCoord * 2.0 - u_resolution.xy) / u_resolution.y;
    vec2 center = u_resolution.xy / 2.0;
    float r = u_resolution.y / 4.0;

    gl_FragColor = vec4(0, 0, 0, 1);
    
    if (distance(gl_FragCoord, center) < r && gl_FragCoord.y > center.y - 1.0)
        gl_FragColor = vec4(0.9, 0, 0, 1);
    float r2 = r / 1.5;
    float r_bottom = center.y - r2;
    if (distance(gl_FragCoord.x, center.x) < r && gl_FragCoord.y > r_bottom && gl_FragCoord.y < center.y + 1.0)
        gl_FragColor = vec4(0.9, 0, 0, 1);
    if (distance(gl_FragCoord.x, center.x) < r && gl_FragCoord.y < r_bottom) 
    {
	if (gl_FragCoord.y > (r_bottom - r2) + r2 * 0.25 * sin(M_PI / 180.0 * (float(u_frame * 5) - (gl_FragCoord.x - center.x) * 5.0)))
        	gl_FragColor = vec4(0.9, 0, 0, 1);
    }
    
    vec2 eye_pos_1 = center;
    eye_pos_1.y += r / 4.0;
    eye_pos_1.x -= r - r / 3.0 - r / 100.0;
    vec2 eye_pos_2 = eye_pos_1;
    eye_pos_2.y -= r / 1.8;
    if (distance(gl_FragCoord, eye_pos_1) + distance(gl_FragCoord, eye_pos_2) < distance(eye_pos_1, eye_pos_2) + r / 4.0)
        gl_FragColor = vec4(1);
    if (distance(gl_FragCoord, eye_pos_2 - vec2(r/12.0,-r/6.0 + 5.0 * sin(M_PI / 180. * float(u_frame)))) < r / 6.0)
        gl_FragColor = vec4(0, 0, 1, 1);
    
    eye_pos_1 = center;
    eye_pos_1.y += r / 4.0;
    eye_pos_2 = eye_pos_1;
    eye_pos_2.y -= r / 1.8;
    if (distance(gl_FragCoord, eye_pos_1) + distance(gl_FragCoord, eye_pos_2) < distance(eye_pos_1, eye_pos_2) + r / 4.0)
        gl_FragColor = vec4(1);
    if (distance(gl_FragCoord, eye_pos_2 - vec2(r/12.0,-r/6.0 + 5.0 * sin(M_PI / 180.0 * float(u_frame)))) < r / 6.0)
        gl_FragColor = vec4(0, 0, 1, 1);
}
