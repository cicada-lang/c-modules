#include "index.h"
#include "../example_button/index.h"

static int run_with_commander(char **args, const commander_t *commander);

void
example_command(const commander_t *commander) {
    command_t *command = command_new("example");
    command->description = "run example programs";
    command->run_with_commander = run_with_commander;
    commander_add(commander, command);
}

static void
print_known_examples(void) {
    printf(
        "[example] known examples: "
        "button"
        "\n");
}

int
run_with_commander(char **args, const commander_t *commander) {
    (void) commander;

    char **names = args + 1;
    char *name = names[0];

    if (!name) {
        printf("[example] expect a given example\n");
        print_known_examples();
        return 1;
    }

    if (string_equal(name, "button")) {
        example_button_start();
        return 0;
    }

    printf("[example] unknown example name: %s\n", name);
    print_known_examples();
    return 1;
}
