VERT
uniform mat4 u_Matrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_ModelViewMatrix;
uniform mat4 u_ProjViewMatrix;
attribute vec3 v_vertex;
attribute vec2 v_coord;
attribute vec3 v_tnormal;

const vec4 u_sun_dir = vec4(0.3, -1.0, 0.0, 0.0);

void main()
{
    float v = dot((u_ModelViewMatrix * vec4(v_tnormal, 0.0)).xyz, (u_ViewMatrix * u_sun_dir).xyz) < 0.0 ? 0.005 : 65535.0;
    gl_Position = u_Matrix * (vec4(v_vertex, 1.0)) + v * u_ProjViewMatrix * u_sun_dir;
}
END

FRAG
void main()
{
  gl_FragColor = vec4(0.05, 0.05, 0.05, 0.25);
}
END