#include "index.h"

void
blob_test(void) {
    printf("<blob_test>\n");

    {
        blob_t *blob = blob_new(3);
        blob_bytes(blob)[0] = 'a';
        blob_bytes(blob)[1] = 'b';
        blob_bytes(blob)[2] = 'c';

        assert(blob_length(blob) == 3);
        assert(string_equal(blob_string(blob), "abc"));

        blob_destroy(&blob);
    }

    {
        blob_t *blob_1 = blob_new(3);
        blob_bytes(blob_1)[0] = 'a';
        blob_bytes(blob_1)[1] = 'b';
        blob_bytes(blob_1)[2] = 'c';

        blob_t *blob_2 = blob_new(3);
        blob_bytes(blob_2)[0] = 'a';
        blob_bytes(blob_2)[1] = 'b';
        blob_bytes(blob_2)[2] = 'c';

        assert(blob_1 != blob_2);
        assert(blob_equal(blob_1, blob_2));

        blob_destroy(&blob_1);
        blob_destroy(&blob_2);
    }

    printf("</blob_test>\n");
}
