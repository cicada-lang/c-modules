#include "index.h"
#include "../image_viewer/index.h"

static int run(commander_t *commander);

void
image_view_command(commander_t *commander) {
    command_t *command = command_new("image:view");
    command->description = "view .icn or .chr image";
    command->run = run;
    commander_add(commander, command);
}

int
run(commander_t *commander) {
    char **paths = commander_rest_argv(commander);
    char *path = paths[0];

    image_viewer_t *image_viewer = image_viewer_new(path);
    image_viewer_open(image_viewer);
    image_viewer_destroy(&image_viewer);

    return 0;
}