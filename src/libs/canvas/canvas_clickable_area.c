#include "index.h"

canvas_clickable_area_t *
canvas_clickable_area_new(
    size_t x, size_t y,
    size_t width, size_t height,
    on_click_t *on_click
) {
    canvas_clickable_area_t *self = allocate(sizeof(canvas_clickable_area_t));
    self->x = x;
    self->y = y;
    self->width = width;
    self->height = height;
    self->on_click = on_click;
    return self;
}

void
canvas_clickable_area_destroy(canvas_clickable_area_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        canvas_clickable_area_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}