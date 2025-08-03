#include <stdint.h>
#include <generic/convert/rgb2rgb.h>

void spl_rgb_convert_line_packed_to_planar(int32_t width, int32_t channels, uint8_t *src, uint8_t **dst)
{
    int32_t col;
    uint8_t *pos = src;

    switch (channels) {
    case 1:
        for (col = 0; col < width; ++col) {
            dst[0][col] = pos[0];
            pos += channels;
        }
        break;
    case 2:
        for (col = 0; col < width; ++col) {
            dst[0][col] = pos[0];
            dst[1][col] = pos[1];
            pos += channels;
        }
        break;
    case 3:
        for (col = 0; col < width; ++col) {
            dst[0][col] = pos[0];
            dst[1][col] = pos[1];
            dst[2][col] = pos[2];
            pos += channels;
        }
        break;
    default:
        for (col = 0; col < width; ++col) {
            dst[0][col] = pos[0];
            dst[1][col] = pos[1];
            dst[2][col] = pos[2];
            dst[3][col] = pos[3];
            pos += channels;
        }
        break;
    }
}

void spl_rgb_convert_line_planar_to_packed(int32_t width, int32_t channels, uint8_t **src, uint8_t *dst)
{
    int32_t col;
    uint8_t *pos = dst;

    switch (channels) {
    case 1:
        for (col = 0; col < width; ++col) {
            pos[0] = src[0][col];
            pos += channels;
        }
        break;
    case 2:
        for (col = 0; col < width; ++col) {
            pos[0] = src[0][col];
            pos[1] = src[1][col];
            pos += channels;
        }
        break;
    case 3:
        for (col = 0; col < width; ++col) {
            pos[0] = src[0][col];
            pos[1] = src[1][col];
            pos[2] = src[2][col];
            pos += channels;
        }
        break;
    default:
        for (col = 0; col < width; ++col) {
            pos[0] = src[0][col];
            pos[1] = src[1][col];
            pos[2] = src[2][col];
            pos[3] = src[3][col];
            pos += channels;
        }
        break;
    }
}
