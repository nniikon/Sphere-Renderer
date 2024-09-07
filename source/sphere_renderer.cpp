#include "sphere_renderer.h"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include <cstdio>

using namespace Sphere;

void Renderer::Render() {
    for (unsigned int x = 0; x < window_width_; x++) {
        for (unsigned int y = 0; y < window_height_; y++) {

            if (!isInBound(x, y)) {
                continue;
            }

            vec3<uint8_t> color = GetPixelColor(x, y);
            SetPixel(x, y, color);
        }
    }
}

const vec3<uint8_t>* Renderer::GetImage() const {
    return pixels_;
}

vec3<uint8_t> Renderer::GetPixelColor(unsigned int x, unsigned int y) const {
    vec3<float> lightness_color     = GetLightness    (x, y);
    vec3<float> highlightness_color = GetHighLightness(x, y);

    return NormalizeColor(color_material * lightness_color + 
                          highlightness_color * 0.5f);
}

vec3<float> Renderer::GetAmbientLight(unsigned int x, unsigned int y) const {
    return color_ambient_;
}

vec3<float> Renderer::GetLightness(unsigned int x, unsigned int y) const {
    vec3<float> surface_point = GetSurfacePointVector(x, y);
    vec3<float> normal        = GetNormalVector(surface_point);
    
    vec3<float> total_light_color = {0.0f, 0.0f, 0.0f};

    for (const LightSource& light : light_sources_) {
        vec3<float> light_direction = Norm(light.position - surface_point);
        float intensity = std::max(0.f, Dot(normal, light_direction));

        total_light_color = total_light_color + light.color * intensity;
    }
    
    return total_light_color;
}

vec3<float> Renderer::GetHighLightness(unsigned int x, unsigned int y) const {
    vec3<float> surface_point = GetSurfacePointVector(x, y);
    vec3<float> normal        = GetNormalVector(surface_point);
    vec3<float> viewer        = Norm(viewer_pos_vector_ - surface_point);
    
    vec3<float> total_highlight_color = {0.0f, 0.0f, 0.0f};

    for (const LightSource& light : light_sources_) {
        vec3<float> light_direction = Norm(light.position - surface_point);
        float light_normal_angle_cos = Dot(light_direction, normal);

        vec3<float> reflaction = normal * light_normal_angle_cos * 2 - light_direction;

        float angle_cos = Dot(reflaction, viewer);
        if (angle_cos > 0) {
            total_highlight_color = total_highlight_color + light.color * powf(angle_cos, 10.f);
        }
    }
    
    return total_highlight_color;
}

uint8_t Renderer::NormalizeChanel(float chanel) const {
    if (chanel > 1.f)
        chanel = 1.f;

    assert(chanel >= 0);

    return static_cast<uint8_t>(chanel * UINT8_MAX);
}

vec3<uint8_t> Renderer::NormalizeColor(vec3<float> color) const {
    return {NormalizeChanel(color.r),
            NormalizeChanel(color.g),
            NormalizeChanel(color.b)};
}

bool Renderer::isInBound(unsigned int x, unsigned int y) const {
    const int r = (int)sphere_raduis_;
    int rel_x = (int)x - (int)sphere_pos_vector_.x;
    int rel_y = (int)y - (int)sphere_pos_vector_.y;

    return (rel_x * rel_x + rel_y * rel_y < r * r);
}

float Renderer::GetThirdCoordinate(float x, float y) const {
    float rf = static_cast<float>(sphere_raduis_);

    float rel_x = sphere_pos_vector_.x - x;
    float rel_y = sphere_pos_vector_.y - y;

    return sqrtf(rf*rf - rel_x*rel_x - rel_y*rel_y) + sphere_pos_vector_.z;
}

vec3<float> Renderer::GetNormalVector(unsigned int x, unsigned int y) const {
    return GetNormalVector(GetSurfacePointVector(x, y));
}

vec3<float> Renderer::GetNormalVector(vec3<float> surface_point) const {
    return Norm(surface_point - sphere_pos_vector_);
}

vec3<float> Renderer::GetSurfacePointVector(unsigned int x, unsigned int y) const {
    float xf = static_cast<float>(x);
    float yf = static_cast<float>(y);
    float zf = GetThirdCoordinate(xf, yf);

    return vec3<float>(xf, yf, zf);
}

void Renderer::SetPixel(unsigned int x, unsigned int y, const vec3<uint8_t>& color) {
    assert(x < window_width_);
    assert(y < window_height_);

    pixels_[y * window_width_ + x] = color;
}

void Renderer::AddLightSource(const vec3<float>& pos, const vec3<float>& color) {
    light_sources_.push_back(LightSource{pos, color});
}

Renderer::Renderer() 
    : pixels_(new vec3<uint8_t>[window_width_ * window_height_]) {
}

Renderer::~Renderer() {
    delete[] pixels_;
}

