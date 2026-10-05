#pragma once

namespace first_person
{

struct camera
{
    float x = 0.0f;
    float y = 0.0f;

    // Direction in radians.
    float angle = 0.0f;

    // 60 degrees.
    float fov = 1.04719755f;

    float near_plane = 0.05f;
    float far_plane = 30.0f;

    void rotate( float radians );
    void move_forward( float distance );
    void move_right( float distance );
};

struct ray
{
    float origin_x;
    float origin_y;

    float direction_x;
    float direction_y;
};

ray make_ray( const camera &cam, int screen_x, int screen_width );

} // namespace first_person
