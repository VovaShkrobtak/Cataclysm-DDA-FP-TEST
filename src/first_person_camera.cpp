#include "first_person_camera.h"

#include <cmath>

namespace first_person
{

namespace
{

constexpr float pi = 3.14159265359f;
constexpr float two_pi = 2.0f * pi;
constexpr float half_pi = 0.5f * pi;

} // namespace

void camera::rotate( float radians )
{
    angle += radians;

    while( angle >= two_pi ) {
        angle -= two_pi;
    }

    while( angle < 0.0f ) {
        angle += two_pi;
    }
}

void camera::move_forward( float distance )
{
    x += std::cos( angle ) * distance;
    y += std::sin( angle ) * distance;
}

void camera::move_right( float distance )
{
    x += std::cos( angle + half_pi ) * distance;
    y += std::sin( angle + half_pi ) * distance;
}

ray make_ray( const camera &cam, int screen_x, int screen_width )
{
    const float screen_center = static_cast<float>( screen_width ) * 0.5f;
    const float normalized =
        ( static_cast<float>( screen_x ) - screen_center ) / screen_center;

    const float ray_angle =
        cam.angle + normalized * ( cam.fov * 0.5f );

    return ray{
        cam.x,
        cam.y,
        std::cos( ray_angle ),
        std::sin( ray_angle )
    };
}

} // namespace first_person
