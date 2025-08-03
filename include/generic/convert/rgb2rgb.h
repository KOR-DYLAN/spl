#ifndef __RGB2RGB__H__
#define __RGB2RGB__H__

extern void spl_rgb_convert_line_packed_to_planar(int32_t width, int32_t channels, uint8_t *src, uint8_t **dst);
extern void spl_rgb_convert_line_planar_to_packed(int32_t width, int32_t channels, uint8_t **src, uint8_t *dst);

#endif  //!__RGB2RGB__H__
