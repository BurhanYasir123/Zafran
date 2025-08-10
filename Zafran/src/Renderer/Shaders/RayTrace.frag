#version 330 core

out vec4 FragColor;
uniform vec4 ourColor;
uniform vec2 WindowSize;

void main()
{
    int CircleRadius = 50;
    int CameraZ = -5;
    float wx = -(gl_FragCoord.x - WindowSize.x / 2.0);
    float wy = -(gl_FragCoord.y - WindowSize.y / 2.0);

    float fx = 100 - wx;
    float fy = 100 - wy;

    float sx = 100 + wx;
    float sy = 100 + wy;

    for(int i=0;i!=5;i++)
    {
        float PosZ = (2)*i;
        float rSquared = (fx*fx + fy*fy + PosZ*PosZ);
        float r2Squared = (sx*sx + sy*sy + PosZ*PosZ);
        

        if(rSquared <= CircleRadius*CircleRadius)
        {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        }

        else if(r2Squared <= CircleRadius*CircleRadius)
        {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        }

        else {
            FragColor = ourColor;
        }
    }
}
