uniform float u_time;
uniform vec3 u_resolution;

vec3 color = vec3(0.3, 0.1, 0.6);

float invader()
{
    float n = 809999.0*fract(sin(dot(floor(gl_FragCoord.xy/8.0).xy,vec2(12.9898,78.233))) * 43758.5357);
    vec2 ip = mod(gl_FragCoord.xy,8.0)-4.0;
    ip.x = abs(ip.x);
    ip.y = floor(ip.y - 5.0);
    return step(ip.x, 2.0) * step(1.0, floor(mod(n/(exp2(floor(ip.x - 3.0*ip.y))),2.0)));
}

float ring()
{
    float t = 0.6*(u_time+0.2*(fract(sin(dot(floor(gl_FragCoord.xy/8.0).xy,vec2(12.9898,78.233))) * 43758.5357)));
    float i = floor(t/2.0);
    vec2 pos = 2.0*vec2(fract(sin(i*0.123) * 4358.5453123), fract(sin(i*2.371) * 4358.5453123))-1.0;
    return smoothstep(0.2, 0.0, abs(length((gl_FragCoord.xy/u_resolution.xy-0.5)-pos)-mod(t,2.0)));
}

void main()
{
    vec2 p = gl_FragCoord.xy;
    vec2 uv = p / u_resolution.xy - 0.5;
    p.y += 120.0*u_time;
    float r = fract(sin(dot(floor(gl_FragCoord.xy/8.0).xy,vec2(12.9898,78.233))) * 43758.5357);
    
    float a = -0.3*smoothstep(0.1, 0.8, length(uv)) + invader() * (0.06 + 0.3*ring() + max(0.0, 0.2*sin(10.0*r*u_time)));
    
    gl_FragColor = vec4(color+a, 1.0);
}