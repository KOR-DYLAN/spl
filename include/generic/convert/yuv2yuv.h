#ifndef __YUV2YUV__H__
#define __YUV2YUV__H__

extern void spl_yuv_convert_line_packed_to_planar(int32_t width, int32_t channels, uint8_t *src, uint8_t **dst);
extern void spl_yuv_convert_line_planar_to_packed(int32_t width, int32_t channels, uint8_t **src, uint8_t *dst);
extern void spl_yuv422_convert_line_interleaved_to_planar(int32_t width, uint8_t *src, uint8_t **dst);
extern void spl_yuv422_convert_line_planar_to_interleaved(int32_t width, uint8_t **src, uint8_t *dst);
extern void spl_yuv420_convert_line_semiplanar_to_planar(int32_t row, int32_t width, uint8_t *src, uint8_t **dst);
extern void spl_yuv420_convert_line_planar_to_semiplanar(int32_t row, int32_t width, uint8_t **src, uint8_t *dst);

#endif  //!__YUV2YUV__H__
