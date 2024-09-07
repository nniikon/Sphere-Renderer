#ifndef SPHERE_RENDERER_H_
#define SPHERE_RENDERER_H_

#include <cinttypes>
#include <vector>
#include "vec.h"

namespace Sphere {

using namespace Vectors;

struct LightSource {
    vec3<float> position;
    vec3<float> color;
};

class Renderer {
private:
    unsigned int window_width_      = 800u; 
    unsigned int window_height_     = 800u; 
    unsigned int sphere_raduis_     = 300u;

    vec3<float>  sphere_pos_vector_ = {400.f, 400.f, 400.f};
    vec3<float>  viewer_pos_vector_ = {350.f, 350.f, 850.f};

    vec3<float> color_ambient_ = {0.0f, 0.0f, 0.0f};
    vec3<float> color_material = {0.8f, 0.4f, 0.3f};

    std::vector<LightSource> light_sources_;

    vec3<uint8_t>* pixels_ = nullptr;

    uint8_t       NormalizeChanel(float chanel)      const;
    vec3<uint8_t> NormalizeColor (vec3<float> color) const;

    bool           isInBound            (unsigned int x, unsigned int y) const;
    float          GetThirdCoordinate   (float x, float y)               const;
    vec3<float>    GetNormalVector      (unsigned int x, unsigned int y) const;
    vec3<float>    GetNormalVector      (vec3<float> surface_point)      const;
    vec3<float>    GetSurfacePointVector(unsigned int x, unsigned int y) const;

    vec3<float>   GetAmbientLight (unsigned int x, unsigned int y) const;
    vec3<float>   GetLightness    (unsigned int x, unsigned int y) const;
    vec3<float>   GetHighLightness(unsigned int x, unsigned int y) const;
    vec3<uint8_t> GetPixelColor   (unsigned int x, unsigned int y) const;

    void SetPixel(unsigned int x, unsigned int y, const vec3<uint8_t>& color);

public:
    Renderer();
    ~Renderer();

    void Render();
    const vec3<uint8_t>* GetImage() const;

    void AddLightSource(const vec3<float>& pos, const vec3<float>& color);
};

}; // namespace

#endif // SPHERE_RENDERER_H_

