#pragma once

// file store with cache

struct store_t {
    const char *base;
    dict_t *cache_dict;
};