#include <stdint.h>
#include <generic/convert/yuv2yuv.h>

void spl_yuv_convert_line_packed_to_planar(int32_t width, int32_t channels, uint8_t *src, uint8_t **dst)
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

void spl_yuv_convert_line_planar_to_packed(int32_t width, int32_t channels, uint8_t **src, uint8_t *dst)
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

void spl_yuv422_convert_line_interleaved_to_planar(int32_t width, uint8_t *src, uint8_t **dst)
{
    int32_t y_col, uv_col;
    int32_t uv_sel;
    uint8_t *pos = src;

    for(y_col = 0; y_col < width; ++y_col) {
        uv_col = y_col / 2;
        uv_sel = (y_col % 2) + 1;
        dst[0][y_col] = pos[0];
        dst[uv_sel][uv_col] = pos[1];
        dst[uv_sel][uv_col] = pos[1];
        pos += 2;
    }

    return 0;
}

void spl_yuv422_convert_line_planar_to_interleaved(int32_t width, uint8_t **src, uint8_t *dst)
{
    int32_t y_col, uv_col;
    int32_t uv_sel;
    uint8_t *pos = dst;

    for(y_col = 0; y_col < width; ++y_col) {
        uv_col = y_col / 2;
        uv_sel = (y_col % 2) + 1;
        pos[0] = src[0][y_col];
        pos[1] = src[uv_sel][uv_col];
        pos += 2;
    }

    return 0;
}

void spl_yuv420_convert_line_semiplanar_to_planar(int32_t row, int32_t width, uint8_t *y_src, uint8_t *uv_src,uint8_t **dst)
{
    int32_t y_col, uv_col;
    int32_t uv_sel;
    uint8_t *pos = src;

    switch(row % 2) {
    case 0: /* even row */
        for(y_col = 0; y_col < width; y_col++) {
            dst[0][y_col] = y_src[y_col];
            dst[1]


            uv_col = y_col / 2;
            uv_sel = (y_col % 2) + 1;
            dst[0][y_col] = pos[0];
            dst[uv_sel][uv_col] = pos[1];
            dst[uv_sel][uv_col] = pos[1];
            pos += 2;
        }
        break;
    default: /* odd row */
        for(y_col = 0; y_col < width; y_col++) {
            uv_col = y_col / 2;
            uv_sel = (y_col % 2) + 1;
            dst[0][y_col] = pos[0];
            pos += 2;
        }
        break;
    }
}

void spl_yuv420_convert_line_planar_to_semiplanar(int32_t row, int32_t width, uint8_t **src, uint8_t *dst)
{
    int32_t y_col, uv_col;
    int32_t uv_sel;
    uint8_t *pos = src;

    switch(row % 2) {
    case 0: /* even row */
        for(y_col = 0; y_col < width; y_col++) {
            uv_col = y_col / 2;
            uv_sel = (y_col % 2) + 1;
            pos[0] = src[0][y_col];
            pos[1] = src[uv_sel][uv_col];
            pos += 2;
        }
        break;
    default: /* odd row */
        for(y_col = 0; y_col < width; y_col++) {
            pos[0] = src[0][y_col];
            pos += 2;
        }
        break;
    }
}
