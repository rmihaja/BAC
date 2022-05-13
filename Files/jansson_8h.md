
# Référence du fichier include/jansson.h

## Structures de données

|                | Nom           |
| -------------- | -------------- |
| struct | **[json_t](/Classes/structjson__t.md)**  |
| struct | **[json_error_t](/Classes/structjson__error__t.md)**  |

## Définitions de type

|                | Nom           |
| -------------- | -------------- |
| enum| **[json_type](/Files/jansson_8h.md#enum-json-type)** { JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_INTEGER, JSON_REAL, JSON_TRUE, JSON_FALSE, JSON_NULL} |
| enum| **[json_error_code](/Files/jansson_8h.md#enum-json-error-code)** { json_error_unknown, json_error_out_of_memory, json_error_stack_overflow, json_error_cannot_open_file, json_error_invalid_argument, json_error_invalid_utf8, json_error_premature_end_of_input, json_error_end_of_input_expected, json_error_invalid_syntax, json_error_invalid_format, json_error_wrong_type, json_error_null_character, json_error_null_value, json_error_null_byte_in_key, json_error_duplicate_key, json_error_numeric_overflow, json_error_item_not_found, json_error_index_out_of_range} |
| typedef struct [json_t](/Classes/structjson__t.md) | **[json_t](/Files/jansson_8h.md#typedef-json-t)**  |
| typedef long | **[json_int_t](/Files/jansson_8h.md#typedef-json-int-t)**  |
| typedef struct [json_error_t](/Classes/structjson__error__t.md) | **[json_error_t](/Files/jansson_8h.md#typedef-json-error-t)**  |
| typedef size_t(*)(void*buffer, size_t buflen, void *data) | **[json_load_callback_t](/Files/jansson_8h.md#typedef-json-load-callback-t)**  |
| typedef int(*)(const char*buffer, size_t size, void *data) | **[json_dump_callback_t](/Files/jansson_8h.md#typedef-json-dump-callback-t)**  |
| typedef void *(*)(size_t) | **[json_malloc_t](/Files/jansson_8h.md#typedef-json-malloc-t)**  |
| typedef void(*)(void*) | **[json_free_t](/Files/jansson_8h.md#typedef-json-free-t)**  |

## Fonctions

|                | Nom           |
| -------------- | -------------- |
| [json_t](/Classes/structjson__t.md) * | **[json_object](/Files/jansson_8h.md#fonction-json-object)**(void ) |
| [json_t](/Classes/structjson__t.md) * | **[json_array](/Files/jansson_8h.md#fonction-json-array)**(void ) |
| [json_t](/Classes/structjson__t.md) * | **[json_string](/Files/jansson_8h.md#fonction-json-string)**(const char * value) |
| [json_t](/Classes/structjson__t.md) * | **[json_stringn](/Files/jansson_8h.md#fonction-json-stringn)**(const char * value, size_t len) |
| [json_t](/Classes/structjson__t.md) * | **[json_string_nocheck](/Files/jansson_8h.md#fonction-json-string-nocheck)**(const char * value) |
| [json_t](/Classes/structjson__t.md) * | **[json_stringn_nocheck](/Files/jansson_8h.md#fonction-json-stringn-nocheck)**(const char * value, size_t len) |
| [json_t](/Classes/structjson__t.md) * | **[json_integer](/Files/jansson_8h.md#fonction-json-integer)**(json_int_t value) |
| [json_t](/Classes/structjson__t.md) * | **[json_real](/Files/jansson_8h.md#fonction-json-real)**(double value) |
| [json_t](/Classes/structjson__t.md) * | **[json_true](/Files/jansson_8h.md#fonction-json-true)**(void ) |
| [json_t](/Classes/structjson__t.md) * | **[json_false](/Files/jansson_8h.md#fonction-json-false)**(void ) |
| [json_t](/Classes/structjson__t.md) * | **[json_null](/Files/jansson_8h.md#fonction-json-null)**(void ) |
| JSON_INLINE [json_t](/Classes/structjson__t.md) * | **[json_incref](/Files/jansson_8h.md#fonction-json-incref)**([json_t](/Classes/structjson__t.md) * json) |
| void | **[json_delete](/Files/jansson_8h.md#fonction-json-delete)**([json_t](/Classes/structjson__t.md) * json) |
| JSON_INLINE void | **[json_decref](/Files/jansson_8h.md#fonction-json-decref)**([json_t](/Classes/structjson__t.md) * json) |
| JSON_INLINE enum json_error_code | **[json_error_code](/Files/jansson_8h.md#fonction-json-error-code)**(const [json_error_t](/Classes/structjson__error__t.md) * e) |
| void | **[json_object_seed](/Files/jansson_8h.md#fonction-json-object-seed)**(size_t seed) |
| size_t | **[json_object_size](/Files/jansson_8h.md#fonction-json-object-size)**(const [json_t](/Classes/structjson__t.md) * object) |
| [json_t](/Classes/structjson__t.md) * | **[json_object_get](/Files/jansson_8h.md#fonction-json-object-get)**(const [json_t](/Classes/structjson__t.md) * object, const char * key) |
| [json_t](/Classes/structjson__t.md) * | **[json_object_getn](/Files/jansson_8h.md#fonction-json-object-getn)**(const [json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len) |
| int | **[json_object_set_new](/Files/jansson_8h.md#fonction-json-object-set-new)**([json_t](/Classes/structjson__t.md) * object, const char * key, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_object_setn_new](/Files/jansson_8h.md#fonction-json-object-setn-new)**([json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_object_set_new_nocheck](/Files/jansson_8h.md#fonction-json-object-set-new-nocheck)**([json_t](/Classes/structjson__t.md) * object, const char * key, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_object_setn_new_nocheck](/Files/jansson_8h.md#fonction-json-object-setn-new-nocheck)**([json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_object_del](/Files/jansson_8h.md#fonction-json-object-del)**([json_t](/Classes/structjson__t.md) * object, const char * key) |
| int | **[json_object_deln](/Files/jansson_8h.md#fonction-json-object-deln)**([json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len) |
| int | **[json_object_clear](/Files/jansson_8h.md#fonction-json-object-clear)**([json_t](/Classes/structjson__t.md) * object) |
| int | **[json_object_update](/Files/jansson_8h.md#fonction-json-object-update)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| int | **[json_object_update_existing](/Files/jansson_8h.md#fonction-json-object-update-existing)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| int | **[json_object_update_missing](/Files/jansson_8h.md#fonction-json-object-update-missing)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| int | **[json_object_update_recursive](/Files/jansson_8h.md#fonction-json-object-update-recursive)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| void * | **[json_object_iter](/Files/jansson_8h.md#fonction-json-object-iter)**([json_t](/Classes/structjson__t.md) * object) |
| void * | **[json_object_iter_at](/Files/jansson_8h.md#fonction-json-object-iter-at)**([json_t](/Classes/structjson__t.md) * object, const char * key) |
| void * | **[json_object_key_to_iter](/Files/jansson_8h.md#fonction-json-object-key-to-iter)**(const char * key) |
| void * | **[json_object_iter_next](/Files/jansson_8h.md#fonction-json-object-iter-next)**([json_t](/Classes/structjson__t.md) * object, void * iter) |
| const char * | **[json_object_iter_key](/Files/jansson_8h.md#fonction-json-object-iter-key)**(void * iter) |
| size_t | **[json_object_iter_key_len](/Files/jansson_8h.md#fonction-json-object-iter-key-len)**(void * iter) |
| [json_t](/Classes/structjson__t.md) * | **[json_object_iter_value](/Files/jansson_8h.md#fonction-json-object-iter-value)**(void * iter) |
| int | **[json_object_iter_set_new](/Files/jansson_8h.md#fonction-json-object-iter-set-new)**([json_t](/Classes/structjson__t.md) * object, void * iter, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_set](/Files/jansson_8h.md#fonction-json-object-set)**([json_t](/Classes/structjson__t.md) * object, const char * key, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_setn](/Files/jansson_8h.md#fonction-json-object-setn)**([json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_set_nocheck](/Files/jansson_8h.md#fonction-json-object-set-nocheck)**([json_t](/Classes/structjson__t.md) * object, const char * key, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_setn_nocheck](/Files/jansson_8h.md#fonction-json-object-setn-nocheck)**([json_t](/Classes/structjson__t.md) * object, const char * key, size_t key_len, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_iter_set](/Files/jansson_8h.md#fonction-json-object-iter-set)**([json_t](/Classes/structjson__t.md) * object, void * iter, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_object_update_new](/Files/jansson_8h.md#fonction-json-object-update-new)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| JSON_INLINE int | **[json_object_update_existing_new](/Files/jansson_8h.md#fonction-json-object-update-existing-new)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| JSON_INLINE int | **[json_object_update_missing_new](/Files/jansson_8h.md#fonction-json-object-update-missing-new)**([json_t](/Classes/structjson__t.md) * object, [json_t](/Classes/structjson__t.md) * other) |
| size_t | **[json_array_size](/Files/jansson_8h.md#fonction-json-array-size)**(const [json_t](/Classes/structjson__t.md) * array) |
| [json_t](/Classes/structjson__t.md) * | **[json_array_get](/Files/jansson_8h.md#fonction-json-array-get)**(const [json_t](/Classes/structjson__t.md) * array, size_t index) |
| int | **[json_array_set_new](/Files/jansson_8h.md#fonction-json-array-set-new)**([json_t](/Classes/structjson__t.md) * array, size_t index, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_array_append_new](/Files/jansson_8h.md#fonction-json-array-append-new)**([json_t](/Classes/structjson__t.md) * array, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_array_insert_new](/Files/jansson_8h.md#fonction-json-array-insert-new)**([json_t](/Classes/structjson__t.md) * array, size_t index, [json_t](/Classes/structjson__t.md) * value) |
| int | **[json_array_remove](/Files/jansson_8h.md#fonction-json-array-remove)**([json_t](/Classes/structjson__t.md) * array, size_t index) |
| int | **[json_array_clear](/Files/jansson_8h.md#fonction-json-array-clear)**([json_t](/Classes/structjson__t.md) * array) |
| int | **[json_array_extend](/Files/jansson_8h.md#fonction-json-array-extend)**([json_t](/Classes/structjson__t.md) * array, [json_t](/Classes/structjson__t.md) * other) |
| JSON_INLINE int | **[json_array_set](/Files/jansson_8h.md#fonction-json-array-set)**([json_t](/Classes/structjson__t.md) * array, size_t ind, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_array_append](/Files/jansson_8h.md#fonction-json-array-append)**([json_t](/Classes/structjson__t.md) * array, [json_t](/Classes/structjson__t.md) * value) |
| JSON_INLINE int | **[json_array_insert](/Files/jansson_8h.md#fonction-json-array-insert)**([json_t](/Classes/structjson__t.md) * array, size_t ind, [json_t](/Classes/structjson__t.md) * value) |
| const char * | **[json_string_value](/Files/jansson_8h.md#fonction-json-string-value)**(const [json_t](/Classes/structjson__t.md) * string) |
| size_t | **[json_string_length](/Files/jansson_8h.md#fonction-json-string-length)**(const [json_t](/Classes/structjson__t.md) * string) |
| json_int_t | **[json_integer_value](/Files/jansson_8h.md#fonction-json-integer-value)**(const [json_t](/Classes/structjson__t.md) * integer) |
| double | **[json_real_value](/Files/jansson_8h.md#fonction-json-real-value)**(const [json_t](/Classes/structjson__t.md) * real) |
| double | **[json_number_value](/Files/jansson_8h.md#fonction-json-number-value)**(const [json_t](/Classes/structjson__t.md) * json) |
| int | **[json_string_set](/Files/jansson_8h.md#fonction-json-string-set)**([json_t](/Classes/structjson__t.md) * string, const char * value) |
| int | **[json_string_setn](/Files/jansson_8h.md#fonction-json-string-setn)**([json_t](/Classes/structjson__t.md) * string, const char * value, size_t len) |
| int | **[json_string_set_nocheck](/Files/jansson_8h.md#fonction-json-string-set-nocheck)**([json_t](/Classes/structjson__t.md) * string, const char * value) |
| int | **[json_string_setn_nocheck](/Files/jansson_8h.md#fonction-json-string-setn-nocheck)**([json_t](/Classes/structjson__t.md) * string, const char * value, size_t len) |
| int | **[json_integer_set](/Files/jansson_8h.md#fonction-json-integer-set)**([json_t](/Classes/structjson__t.md) * integer, json_int_t value) |
| int | **[json_real_set](/Files/jansson_8h.md#fonction-json-real-set)**([json_t](/Classes/structjson__t.md) * real, double value) |
| [json_t](/Classes/structjson__t.md) * | **[json_pack](/Files/jansson_8h.md#fonction-json-pack)**(const char * fmt, ... ) |
| [json_t](/Classes/structjson__t.md) * | **[json_pack_ex](/Files/jansson_8h.md#fonction-json-pack-ex)**([json_error_t](/Classes/structjson__error__t.md) * error, size_t flags, const char * fmt, ... ) |
| [json_t](/Classes/structjson__t.md) * | **[json_vpack_ex](/Files/jansson_8h.md#fonction-json-vpack-ex)**([json_error_t](/Classes/structjson__error__t.md) * error, size_t flags, const char * fmt, va_list ap) |
| int | **[json_unpack](/Files/jansson_8h.md#fonction-json-unpack)**([json_t](/Classes/structjson__t.md) * root, const char * fmt, ... ) |
| int | **[json_unpack_ex](/Files/jansson_8h.md#fonction-json-unpack-ex)**([json_t](/Classes/structjson__t.md) * root, [json_error_t](/Classes/structjson__error__t.md) * error, size_t flags, const char * fmt, ... ) |
| int | **[json_vunpack_ex](/Files/jansson_8h.md#fonction-json-vunpack-ex)**([json_t](/Classes/structjson__t.md) * root, [json_error_t](/Classes/structjson__error__t.md) * error, size_t flags, const char * fmt, va_list ap) |
| [json_t](/Classes/structjson__t.md) * | **[json_sprintf](/Files/jansson_8h.md#fonction-json-sprintf)**(const char * fmt, ... ) |
| [json_t](/Classes/structjson__t.md) | **[format](/Files/jansson_8h.md#fonction-format)**(printf , 1 , 2 ) |
| [json_t](/Classes/structjson__t.md) * | **[json_vsprintf](/Files/jansson_8h.md#fonction-json-vsprintf)**(const char * fmt, va_list ap) |
| [json_t](/Classes/structjson__t.md) | **[format](/Files/jansson_8h.md#fonction-format)**(printf , 1 , 0 ) |
| int | **[json_equal](/Files/jansson_8h.md#fonction-json-equal)**(const [json_t](/Classes/structjson__t.md) *value1, const [json_t](/Classes/structjson__t.md)* value2) |
| [json_t](/Classes/structjson__t.md) * | **[json_copy](/Files/jansson_8h.md#fonction-json-copy)**([json_t](/Classes/structjson__t.md) * value) |
| [json_t](/Classes/structjson__t.md) * | **[json_deep_copy](/Files/jansson_8h.md#fonction-json-deep-copy)**(const [json_t](/Classes/structjson__t.md) * value) |
| [json_t](/Classes/structjson__t.md) * | **[json_loads](/Files/jansson_8h.md#fonction-json-loads)**(const char * input, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| [json_t](/Classes/structjson__t.md) * | **[json_loadb](/Files/jansson_8h.md#fonction-json-loadb)**(const char * buffer, size_t buflen, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| [json_t](/Classes/structjson__t.md) * | **[json_loadf](/Files/jansson_8h.md#fonction-json-loadf)**(FILE * input, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| [json_t](/Classes/structjson__t.md) * | **[json_loadfd](/Files/jansson_8h.md#fonction-json-loadfd)**(int input, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| [json_t](/Classes/structjson__t.md) * | **[json_load_file](/Files/jansson_8h.md#fonction-json-load-file)**(const char * path, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| [json_t](/Classes/structjson__t.md) * | **[json_load_callback](/Files/jansson_8h.md#fonction-json-load-callback)**(json_load_callback_t callback, void * data, size_t flags, [json_error_t](/Classes/structjson__error__t.md) * error) |
| char * | **[json_dumps](/Files/jansson_8h.md#fonction-json-dumps)**(const [json_t](/Classes/structjson__t.md) * json, size_t flags) |
| size_t | **[json_dumpb](/Files/jansson_8h.md#fonction-json-dumpb)**(const [json_t](/Classes/structjson__t.md) *json, char* buffer, size_t size, size_t flags) |
| int | **[json_dumpf](/Files/jansson_8h.md#fonction-json-dumpf)**(const [json_t](/Classes/structjson__t.md) *json, FILE* output, size_t flags) |
| int | **[json_dumpfd](/Files/jansson_8h.md#fonction-json-dumpfd)**(const [json_t](/Classes/structjson__t.md) * json, int output, size_t flags) |
| int | **[json_dump_file](/Files/jansson_8h.md#fonction-json-dump-file)**(const [json_t](/Classes/structjson__t.md) *json, const char* path, size_t flags) |
| int | **[json_dump_callback](/Files/jansson_8h.md#fonction-json-dump-callback)**(const [json_t](/Classes/structjson__t.md) *json, json_dump_callback_t callback, void* data, size_t flags) |
| void | **[json_set_alloc_funcs](/Files/jansson_8h.md#fonction-json-set-alloc-funcs)**(json_malloc_t malloc_fn, json_free_t free_fn) |
| void | **[json_get_alloc_funcs](/Files/jansson_8h.md#fonction-json-get-alloc-funcs)**(json_malloc_t *malloc_fn, json_free_t* free_fn) |
| const char * | **[jansson_version_str](/Files/jansson_8h.md#fonction-jansson-version-str)**(void ) |
| int | **[jansson_version_cmp](/Files/jansson_8h.md#fonction-jansson-version-cmp)**(int major, int minor, int micro) |

## Macros

|                | Nom           |
| -------------- | -------------- |
|  | **[JANSSON_MAJOR_VERSION](/Files/jansson_8h.md#define-jansson-major-version)**  |
|  | **[JANSSON_MINOR_VERSION](/Files/jansson_8h.md#define-jansson-minor-version)**  |
|  | **[JANSSON_MICRO_VERSION](/Files/jansson_8h.md#define-jansson-micro-version)**  |
|  | **[JANSSON_VERSION](/Files/jansson_8h.md#define-jansson-version)**  |
|  | **[JANSSON_VERSION_HEX](/Files/jansson_8h.md#define-jansson-version-hex)**  |
|  | **[JANSSON_ATTRS](/Files/jansson_8h.md#define-jansson-attrs)**(x)  |
|  | **[JSON_INTEGER_FORMAT](/Files/jansson_8h.md#define-json-integer-format)**  |
|  | **[json_typeof](/Files/jansson_8h.md#define-json-typeof)**(json)  |
|  | **[json_is_object](/Files/jansson_8h.md#define-json-is-object)**(json)  |
|  | **[json_is_array](/Files/jansson_8h.md#define-json-is-array)**(json)  |
|  | **[json_is_string](/Files/jansson_8h.md#define-json-is-string)**(json)  |
|  | **[json_is_integer](/Files/jansson_8h.md#define-json-is-integer)**(json)  |
|  | **[json_is_real](/Files/jansson_8h.md#define-json-is-real)**(json)  |
|  | **[json_is_number](/Files/jansson_8h.md#define-json-is-number)**(json)  |
|  | **[json_is_true](/Files/jansson_8h.md#define-json-is-true)**(json)  |
|  | **[json_is_false](/Files/jansson_8h.md#define-json-is-false)**(json)  |
|  | **[json_boolean_value](/Files/jansson_8h.md#define-json-boolean-value)**  |
|  | **[json_is_boolean](/Files/jansson_8h.md#define-json-is-boolean)**(json)  |
|  | **[json_is_null](/Files/jansson_8h.md#define-json-is-null)**(json)  |
|  | **[json_boolean](/Files/jansson_8h.md#define-json-boolean)**(val)  |
|  | **[JSON_INTERNAL_INCREF](/Files/jansson_8h.md#define-json-internal-incref)**(json)  |
|  | **[JSON_INTERNAL_DECREF](/Files/jansson_8h.md#define-json-internal-decref)**(json)  |
|  | **[JSON_ERROR_TEXT_LENGTH](/Files/jansson_8h.md#define-json-error-text-length)**  |
|  | **[JSON_ERROR_SOURCE_LENGTH](/Files/jansson_8h.md#define-json-error-source-length)**  |
|  | **[json_object_foreach](/Files/jansson_8h.md#define-json-object-foreach)**(object, key, value)  |
|  | **[json_object_keylen_foreach](/Files/jansson_8h.md#define-json-object-keylen-foreach)**(object, key, key_len, value)  |
|  | **[json_object_foreach_safe](/Files/jansson_8h.md#define-json-object-foreach-safe)**(object, n, key, value)  |
|  | **[json_object_keylen_foreach_safe](/Files/jansson_8h.md#define-json-object-keylen-foreach-safe)**(object, n, key, key_len, value)  |
|  | **[json_array_foreach](/Files/jansson_8h.md#define-json-array-foreach)**(array, index, value)  |
|  | **[JSON_VALIDATE_ONLY](/Files/jansson_8h.md#define-json-validate-only)**  |
|  | **[JSON_STRICT](/Files/jansson_8h.md#define-json-strict)**  |
|  | **[JSON_REJECT_DUPLICATES](/Files/jansson_8h.md#define-json-reject-duplicates)**  |
|  | **[JSON_DISABLE_EOF_CHECK](/Files/jansson_8h.md#define-json-disable-eof-check)**  |
|  | **[JSON_DECODE_ANY](/Files/jansson_8h.md#define-json-decode-any)**  |
|  | **[JSON_DECODE_INT_AS_REAL](/Files/jansson_8h.md#define-json-decode-int-as-real)**  |
|  | **[JSON_ALLOW_NUL](/Files/jansson_8h.md#define-json-allow-nul)**  |
|  | **[JSON_MAX_INDENT](/Files/jansson_8h.md#define-json-max-indent)**  |
|  | **[JSON_INDENT](/Files/jansson_8h.md#define-json-indent)**(n)  |
|  | **[JSON_COMPACT](/Files/jansson_8h.md#define-json-compact)**  |
|  | **[JSON_ENSURE_ASCII](/Files/jansson_8h.md#define-json-ensure-ascii)**  |
|  | **[JSON_SORT_KEYS](/Files/jansson_8h.md#define-json-sort-keys)**  |
|  | **[JSON_PRESERVE_ORDER](/Files/jansson_8h.md#define-json-preserve-order)**  |
|  | **[JSON_ENCODE_ANY](/Files/jansson_8h.md#define-json-encode-any)**  |
|  | **[JSON_ESCAPE_SLASH](/Files/jansson_8h.md#define-json-escape-slash)**  |
|  | **[JSON_REAL_PRECISION](/Files/jansson_8h.md#define-json-real-precision)**(n)  |
|  | **[JSON_EMBED](/Files/jansson_8h.md#define-json-embed)**  |

## Documentation des types

### enum json_type

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| JSON_OBJECT | |   |
| JSON_ARRAY | |   |
| JSON_STRING | |   |
| JSON_INTEGER | |   |
| JSON_REAL | |   |
| JSON_TRUE | |   |
| JSON_FALSE | |   |
| JSON_NULL | |   |

### enum json_error_code

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| json_error_unknown | |   |
| json_error_out_of_memory | |   |
| json_error_stack_overflow | |   |
| json_error_cannot_open_file | |   |
| json_error_invalid_argument | |   |
| json_error_invalid_utf8 | |   |
| json_error_premature_end_of_input | |   |
| json_error_end_of_input_expected | |   |
| json_error_invalid_syntax | |   |
| json_error_invalid_format | |   |
| json_error_wrong_type | |   |
| json_error_null_character | |   |
| json_error_null_value | |   |
| json_error_null_byte_in_key | |   |
| json_error_duplicate_key | |   |
| json_error_numeric_overflow | |   |
| json_error_item_not_found | |   |
| json_error_index_out_of_range | |   |

### typedef json_t

```c
typedef struct json_t json_t;
```

### typedef json_int_t

```c
typedef long json_int_t;
```

### typedef json_error_t

```c
typedef struct json_error_t json_error_t;
```

### typedef json_load_callback_t

```c
typedef size_t(* json_load_callback_t) (void *buffer, size_t buflen, void *data);
```

### typedef json_dump_callback_t

```c
typedef int(* json_dump_callback_t) (const char *buffer, size_t size, void *data);
```

### typedef json_malloc_t

```c
typedef void *(* json_malloc_t) (size_t);
```

### typedef json_free_t

```c
typedef void(* json_free_t) (void *);
```

## Documentation des fonctions

### fonction json_object()

```c
json_t * json_object(
    void
)
```

### fonction json_array()

```c
json_t * json_array(
    void
)
```

### fonction json_string()

```c
json_t * json_string(
    const char * value
)
```

### fonction json_stringn()

```c
json_t * json_stringn(
    const char * value,
    size_t len
)
```

### fonction json_string_nocheck()

```c
json_t * json_string_nocheck(
    const char * value
)
```

### fonction json_stringn_nocheck()

```c
json_t * json_stringn_nocheck(
    const char * value,
    size_t len
)
```

### fonction json_integer()

```c
json_t * json_integer(
    json_int_t value
)
```

### fonction json_real()

```c
json_t * json_real(
    double value
)
```

### fonction json_true()

```c
json_t * json_true(
    void
)
```

### fonction json_false()

```c
json_t * json_false(
    void
)
```

### fonction json_null()

```c
json_t * json_null(
    void
)
```

### fonction json_incref()

```c
static JSON_INLINE json_t * json_incref(
    json_t * json
)
```

### fonction json_delete()

```c
void json_delete(
    json_t * json
)
```

### fonction json_decref()

```c
static JSON_INLINE void json_decref(
    json_t * json
)
```

### fonction json_error_code()

```c
static JSON_INLINE enum json_error_code json_error_code(
    const json_error_t * e
)
```

### fonction json_object_seed()

```c
void json_object_seed(
    size_t seed
)
```

### fonction json_object_size()

```c
size_t json_object_size(
    const json_t * object
)
```

### fonction json_object_get()

```c
json_t * json_object_get(
    const json_t * object,
    const char * key
)
```

### fonction json_object_getn()

```c
json_t * json_object_getn(
    const json_t * object,
    const char * key,
    size_t key_len
)
```

### fonction json_object_set_new()

```c
int json_object_set_new(
    json_t * object,
    const char * key,
    json_t * value
)
```

### fonction json_object_setn_new()

```c
int json_object_setn_new(
    json_t * object,
    const char * key,
    size_t key_len,
    json_t * value
)
```

### fonction json_object_set_new_nocheck()

```c
int json_object_set_new_nocheck(
    json_t * object,
    const char * key,
    json_t * value
)
```

### fonction json_object_setn_new_nocheck()

```c
int json_object_setn_new_nocheck(
    json_t * object,
    const char * key,
    size_t key_len,
    json_t * value
)
```

### fonction json_object_del()

```c
int json_object_del(
    json_t * object,
    const char * key
)
```

### fonction json_object_deln()

```c
int json_object_deln(
    json_t * object,
    const char * key,
    size_t key_len
)
```

### fonction json_object_clear()

```c
int json_object_clear(
    json_t * object
)
```

### fonction json_object_update()

```c
int json_object_update(
    json_t * object,
    json_t * other
)
```

### fonction json_object_update_existing()

```c
int json_object_update_existing(
    json_t * object,
    json_t * other
)
```

### fonction json_object_update_missing()

```c
int json_object_update_missing(
    json_t * object,
    json_t * other
)
```

### fonction json_object_update_recursive()

```c
int json_object_update_recursive(
    json_t * object,
    json_t * other
)
```

### fonction json_object_iter()

```c
void * json_object_iter(
    json_t * object
)
```

### fonction json_object_iter_at()

```c
void * json_object_iter_at(
    json_t * object,
    const char * key
)
```

### fonction json_object_key_to_iter()

```c
void * json_object_key_to_iter(
    const char * key
)
```

### fonction json_object_iter_next()

```c
void * json_object_iter_next(
    json_t * object,
    void * iter
)
```

### fonction json_object_iter_key()

```c
const char * json_object_iter_key(
    void * iter
)
```

### fonction json_object_iter_key_len()

```c
size_t json_object_iter_key_len(
    void * iter
)
```

### fonction json_object_iter_value()

```c
json_t * json_object_iter_value(
    void * iter
)
```

### fonction json_object_iter_set_new()

```c
int json_object_iter_set_new(
    json_t * object,
    void * iter,
    json_t * value
)
```

### fonction json_object_set()

```c
static JSON_INLINE int json_object_set(
    json_t * object,
    const char * key,
    json_t * value
)
```

### fonction json_object_setn()

```c
static JSON_INLINE int json_object_setn(
    json_t * object,
    const char * key,
    size_t key_len,
    json_t * value
)
```

### fonction json_object_set_nocheck()

```c
static JSON_INLINE int json_object_set_nocheck(
    json_t * object,
    const char * key,
    json_t * value
)
```

### fonction json_object_setn_nocheck()

```c
static JSON_INLINE int json_object_setn_nocheck(
    json_t * object,
    const char * key,
    size_t key_len,
    json_t * value
)
```

### fonction json_object_iter_set()

```c
static JSON_INLINE int json_object_iter_set(
    json_t * object,
    void * iter,
    json_t * value
)
```

### fonction json_object_update_new()

```c
static JSON_INLINE int json_object_update_new(
    json_t * object,
    json_t * other
)
```

### fonction json_object_update_existing_new()

```c
static JSON_INLINE int json_object_update_existing_new(
    json_t * object,
    json_t * other
)
```

### fonction json_object_update_missing_new()

```c
static JSON_INLINE int json_object_update_missing_new(
    json_t * object,
    json_t * other
)
```

### fonction json_array_size()

```c
size_t json_array_size(
    const json_t * array
)
```

### fonction json_array_get()

```c
json_t * json_array_get(
    const json_t * array,
    size_t index
)
```

### fonction json_array_set_new()

```c
int json_array_set_new(
    json_t * array,
    size_t index,
    json_t * value
)
```

### fonction json_array_append_new()

```c
int json_array_append_new(
    json_t * array,
    json_t * value
)
```

### fonction json_array_insert_new()

```c
int json_array_insert_new(
    json_t * array,
    size_t index,
    json_t * value
)
```

### fonction json_array_remove()

```c
int json_array_remove(
    json_t * array,
    size_t index
)
```

### fonction json_array_clear()

```c
int json_array_clear(
    json_t * array
)
```

### fonction json_array_extend()

```c
int json_array_extend(
    json_t * array,
    json_t * other
)
```

### fonction json_array_set()

```c
static JSON_INLINE int json_array_set(
    json_t * array,
    size_t ind,
    json_t * value
)
```

### fonction json_array_append()

```c
static JSON_INLINE int json_array_append(
    json_t * array,
    json_t * value
)
```

### fonction json_array_insert()

```c
static JSON_INLINE int json_array_insert(
    json_t * array,
    size_t ind,
    json_t * value
)
```

### fonction json_string_value()

```c
const char * json_string_value(
    const json_t * string
)
```

### fonction json_string_length()

```c
size_t json_string_length(
    const json_t * string
)
```

### fonction json_integer_value()

```c
json_int_t json_integer_value(
    const json_t * integer
)
```

### fonction json_real_value()

```c
double json_real_value(
    const json_t * real
)
```

### fonction json_number_value()

```c
double json_number_value(
    const json_t * json
)
```

### fonction json_string_set()

```c
int json_string_set(
    json_t * string,
    const char * value
)
```

### fonction json_string_setn()

```c
int json_string_setn(
    json_t * string,
    const char * value,
    size_t len
)
```

### fonction json_string_set_nocheck()

```c
int json_string_set_nocheck(
    json_t * string,
    const char * value
)
```

### fonction json_string_setn_nocheck()

```c
int json_string_setn_nocheck(
    json_t * string,
    const char * value,
    size_t len
)
```

### fonction json_integer_set()

```c
int json_integer_set(
    json_t * integer,
    json_int_t value
)
```

### fonction json_real_set()

```c
int json_real_set(
    json_t * real,
    double value
)
```

### fonction json_pack()

```c
json_t * json_pack(
    const char * fmt,
    ...
)
```

### fonction json_pack_ex()

```c
json_t * json_pack_ex(
    json_error_t * error,
    size_t flags,
    const char * fmt,
    ...
)
```

### fonction json_vpack_ex()

```c
json_t * json_vpack_ex(
    json_error_t * error,
    size_t flags,
    const char * fmt,
    va_list ap
)
```

### fonction json_unpack()

```c
int json_unpack(
    json_t * root,
    const char * fmt,
    ...
)
```

### fonction json_unpack_ex()

```c
int json_unpack_ex(
    json_t * root,
    json_error_t * error,
    size_t flags,
    const char * fmt,
    ...
)
```

### fonction json_vunpack_ex()

```c
int json_vunpack_ex(
    json_t * root,
    json_error_t * error,
    size_t flags,
    const char * fmt,
    va_list ap
)
```

### fonction json_sprintf()

```c
json_t * json_sprintf(
    const char * fmt,
    ...
)
```

### fonction format()

```c
json_t format(
    printf ,
    1 ,
    2
)
```

### fonction json_vsprintf()

```c
json_t * json_vsprintf(
    const char * fmt,
    va_list ap
)
```

### fonction format()

```c
json_t format(
    printf ,
    1 ,
    0
)
```

### fonction json_equal()

```c
int json_equal(
    const json_t * value1,
    const json_t * value2
)
```

### fonction json_copy()

```c
json_t * json_copy(
    json_t * value
)
```

### fonction json_deep_copy()

```c
json_t * json_deep_copy(
    const json_t * value
)
```

### fonction json_loads()

```c
json_t * json_loads(
    const char * input,
    size_t flags,
    json_error_t * error
)
```

### fonction json_loadb()

```c
json_t * json_loadb(
    const char * buffer,
    size_t buflen,
    size_t flags,
    json_error_t * error
)
```

### fonction json_loadf()

```c
json_t * json_loadf(
    FILE * input,
    size_t flags,
    json_error_t * error
)
```

### fonction json_loadfd()

```c
json_t * json_loadfd(
    int input,
    size_t flags,
    json_error_t * error
)
```

### fonction json_load_file()

```c
json_t * json_load_file(
    const char * path,
    size_t flags,
    json_error_t * error
)
```

### fonction json_load_callback()

```c
json_t * json_load_callback(
    json_load_callback_t callback,
    void * data,
    size_t flags,
    json_error_t * error
)
```

### fonction json_dumps()

```c
char * json_dumps(
    const json_t * json,
    size_t flags
)
```

### fonction json_dumpb()

```c
size_t json_dumpb(
    const json_t * json,
    char * buffer,
    size_t size,
    size_t flags
)
```

### fonction json_dumpf()

```c
int json_dumpf(
    const json_t * json,
    FILE * output,
    size_t flags
)
```

### fonction json_dumpfd()

```c
int json_dumpfd(
    const json_t * json,
    int output,
    size_t flags
)
```

### fonction json_dump_file()

```c
int json_dump_file(
    const json_t * json,
    const char * path,
    size_t flags
)
```

### fonction json_dump_callback()

```c
int json_dump_callback(
    const json_t * json,
    json_dump_callback_t callback,
    void * data,
    size_t flags
)
```

### fonction json_set_alloc_funcs()

```c
void json_set_alloc_funcs(
    json_malloc_t malloc_fn,
    json_free_t free_fn
)
```

### fonction json_get_alloc_funcs()

```c
void json_get_alloc_funcs(
    json_malloc_t * malloc_fn,
    json_free_t * free_fn
)
```

### fonction jansson_version_str()

```c
const char * jansson_version_str(
    void
)
```

### fonction jansson_version_cmp()

```c
int jansson_version_cmp(
    int major,
    int minor,
    int micro
)
```

## Documentation des macros

### define JANSSON_MAJOR_VERSION

```c
#define JANSSON_MAJOR_VERSION 2
```

### define JANSSON_MINOR_VERSION

```c
#define JANSSON_MINOR_VERSION 14
```

### define JANSSON_MICRO_VERSION

```c
#define JANSSON_MICRO_VERSION 0
```

### define JANSSON_VERSION

```c
#define JANSSON_VERSION "2.14"
```

### define JANSSON_VERSION_HEX

```c
#define JANSSON_VERSION_HEX     ((JANSSON_MAJOR_VERSION << 16) | (JANSSON_MINOR_VERSION << 8) |                      \
     (JANSSON_MICRO_VERSION << 0))
```

### define JANSSON_ATTRS

```c
#define JANSSON_ATTRS(
    x
)

```

### define JSON_INTEGER_FORMAT

```c
#define JSON_INTEGER_FORMAT "ld"
```

### define json_typeof

```c
#define json_typeof(
    json
)
((json)->type)
```

### define json_is_object

```c
#define json_is_object(
    json
)
((json) && json_typeof(json) == JSON_OBJECT)
```

### define json_is_array

```c
#define json_is_array(
    json
)
((json) && json_typeof(json) == JSON_ARRAY)
```

### define json_is_string

```c
#define json_is_string(
    json
)
((json) && json_typeof(json) == JSON_STRING)
```

### define json_is_integer

```c
#define json_is_integer(
    json
)
((json) && json_typeof(json) == JSON_INTEGER)
```

### define json_is_real

```c
#define json_is_real(
    json
)
((json) && json_typeof(json) == JSON_REAL)
```

### define json_is_number

```c
#define json_is_number(
    json
)
(json_is_integer(json) || json_is_real(json))
```

### define json_is_true

```c
#define json_is_true(
    json
)
((json) && json_typeof(json) == JSON_TRUE)
```

### define json_is_false

```c
#define json_is_false(
    json
)
((json) && json_typeof(json) == JSON_FALSE)
```

### define json_boolean_value

```c
#define json_boolean_value json_is_true
```

### define json_is_boolean

```c
#define json_is_boolean(
    json
)
(json_is_true(json) || json_is_false(json))
```

### define json_is_null

```c
#define json_is_null(
    json
)
((json) && json_typeof(json) == JSON_NULL)
```

### define json_boolean

```c
#define json_boolean(
    val
)
((val) ? json_true() : json_false())
```

### define JSON_INTERNAL_INCREF

```c
#define JSON_INTERNAL_INCREF(
    json
)
(++json->refcount)
```

### define JSON_INTERNAL_DECREF

```c
#define JSON_INTERNAL_DECREF(
    json
)
(--json->refcount)
```

### define JSON_ERROR_TEXT_LENGTH

```c
#define JSON_ERROR_TEXT_LENGTH 160
```

### define JSON_ERROR_SOURCE_LENGTH

```c
#define JSON_ERROR_SOURCE_LENGTH 80
```

### define json_object_foreach

```c
#define json_object_foreach(
    object,
    key,
    value
)
    for (key = json_object_iter_key(json_object_iter(object));                           \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(                                                     \
             json_object_iter_next(object, json_object_key_to_iter(key))))
```

### define json_object_keylen_foreach

```c
#define json_object_keylen_foreach(
    object,
    key,
    key_len,
    value
)
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key));                \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(                                                     \
             json_object_iter_next(object, json_object_key_to_iter(key))),               \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key)))
```

### define json_object_foreach_safe

```c
#define json_object_foreach_safe(
    object,
    n,
    key,
    value
)
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        n = json_object_iter_next(object, json_object_key_to_iter(key));                 \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(n),                                                  \
        n = json_object_iter_next(object, json_object_key_to_iter(key)))
```

### define json_object_keylen_foreach_safe

```c
#define json_object_keylen_foreach_safe(
    object,
    n,
    key,
    key_len,
    value
)
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        n = json_object_iter_next(object, json_object_key_to_iter(key)),                 \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key));                \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(n), key_len = json_object_iter_key_len(n),           \
        n = json_object_iter_next(object, json_object_key_to_iter(key)))
```

### define json_array_foreach

```c
#define json_array_foreach(
    array,
    index,
    value
)
    for (index = 0;                                                                      \
         index < json_array_size(array) && (value = json_array_get(array, index));       \
         index++)
```

### define JSON_VALIDATE_ONLY

```c
#define JSON_VALIDATE_ONLY 0x1
```

### define JSON_STRICT

```c
#define JSON_STRICT 0x2
```

### define JSON_REJECT_DUPLICATES

```c
#define JSON_REJECT_DUPLICATES 0x1
```

### define JSON_DISABLE_EOF_CHECK

```c
#define JSON_DISABLE_EOF_CHECK 0x2
```

### define JSON_DECODE_ANY

```c
#define JSON_DECODE_ANY 0x4
```

### define JSON_DECODE_INT_AS_REAL

```c
#define JSON_DECODE_INT_AS_REAL 0x8
```

### define JSON_ALLOW_NUL

```c
#define JSON_ALLOW_NUL 0x10
```

### define JSON_MAX_INDENT

```c
#define JSON_MAX_INDENT 0x1F
```

### define JSON_INDENT

```c
#define JSON_INDENT(
    n
)
((n)&JSON_MAX_INDENT)
```

### define JSON_COMPACT

```c
#define JSON_COMPACT 0x20
```

### define JSON_ENSURE_ASCII

```c
#define JSON_ENSURE_ASCII 0x40
```

### define JSON_SORT_KEYS

```c
#define JSON_SORT_KEYS 0x80
```

### define JSON_PRESERVE_ORDER

```c
#define JSON_PRESERVE_ORDER 0x100
```

### define JSON_ENCODE_ANY

```c
#define JSON_ENCODE_ANY 0x200
```

### define JSON_ESCAPE_SLASH

```c
#define JSON_ESCAPE_SLASH 0x400
```

### define JSON_REAL_PRECISION

```c
#define JSON_REAL_PRECISION(
    n
)
(((n)&0x1F) << 11)
```

### define JSON_EMBED

```c
#define JSON_EMBED 0x10000
```

## Code source

```c
/*
 * Copyright (c) 2009-2016 Petri Lehtinen <petri@digip.org>
 *
 * Jansson is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef JANSSON_H
#define JANSSON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h> /* for size_t */

#include "jansson_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* version */

#define JANSSON_MAJOR_VERSION 2
#define JANSSON_MINOR_VERSION 14
#define JANSSON_MICRO_VERSION 0

/* Micro version is omitted if it's 0 */
#define JANSSON_VERSION "2.14"

/* Version as a 3-byte hex number, e.g. 0x010201 == 1.2.1. Use this
   for numeric comparisons, e.g. #if JANSSON_VERSION_HEX >= ... */
#define JANSSON_VERSION_HEX                                                              \
    ((JANSSON_MAJOR_VERSION << 16) | (JANSSON_MINOR_VERSION << 8) |                      \
     (JANSSON_MICRO_VERSION << 0))

/* If __atomic or __sync builtins are available the library is thread
 * safe for all read-only functions plus reference counting. */
#if JSON_HAVE_ATOMIC_BUILTINS || JSON_HAVE_SYNC_BUILTINS
#define JANSSON_THREAD_SAFE_REFCOUNT 1
#endif

#if defined(__GNUC__) || defined(__clang__)
#define JANSSON_ATTRS(x) __attribute__(x)
#else
#define JANSSON_ATTRS(x)
#endif

/* types */

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_INTEGER,
    JSON_REAL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct json_t {
    json_type type;
    volatile size_t refcount;
} json_t;

#ifndef JANSSON_USING_CMAKE /* disabled if using cmake */
#if JSON_INTEGER_IS_LONG_LONG
#ifdef _WIN32
#define JSON_INTEGER_FORMAT "I64d"
#else
#define JSON_INTEGER_FORMAT "lld"
#endif
typedef long long json_int_t;
#else
#define JSON_INTEGER_FORMAT "ld"
typedef long json_int_t;
#endif /* JSON_INTEGER_IS_LONG_LONG */
#endif

#define json_typeof(json)     ((json)->type)
#define json_is_object(json)  ((json) && json_typeof(json) == JSON_OBJECT)
#define json_is_array(json)   ((json) && json_typeof(json) == JSON_ARRAY)
#define json_is_string(json)  ((json) && json_typeof(json) == JSON_STRING)
#define json_is_integer(json) ((json) && json_typeof(json) == JSON_INTEGER)
#define json_is_real(json)    ((json) && json_typeof(json) == JSON_REAL)
#define json_is_number(json)  (json_is_integer(json) || json_is_real(json))
#define json_is_true(json)    ((json) && json_typeof(json) == JSON_TRUE)
#define json_is_false(json)   ((json) && json_typeof(json) == JSON_FALSE)
#define json_boolean_value    json_is_true
#define json_is_boolean(json) (json_is_true(json) || json_is_false(json))
#define json_is_null(json)    ((json) && json_typeof(json) == JSON_NULL)

/* construction, destruction, reference counting */

json_t *json_object(void);
json_t *json_array(void);
json_t *json_string(const char *value);
json_t *json_stringn(const char *value, size_t len);
json_t *json_string_nocheck(const char *value);
json_t *json_stringn_nocheck(const char *value, size_t len);
json_t *json_integer(json_int_t value);
json_t *json_real(double value);
json_t *json_true(void);
json_t *json_false(void);
#define json_boolean(val) ((val) ? json_true() : json_false())
json_t *json_null(void);

/* do not call JSON_INTERNAL_INCREF or JSON_INTERNAL_DECREF directly */
#if JSON_HAVE_ATOMIC_BUILTINS
#define JSON_INTERNAL_INCREF(json)                                                       \
    __atomic_add_fetch(&json->refcount, 1, __ATOMIC_ACQUIRE)
#define JSON_INTERNAL_DECREF(json)                                                       \
    __atomic_sub_fetch(&json->refcount, 1, __ATOMIC_RELEASE)
#elif JSON_HAVE_SYNC_BUILTINS
#define JSON_INTERNAL_INCREF(json) __sync_add_and_fetch(&json->refcount, 1)
#define JSON_INTERNAL_DECREF(json) __sync_sub_and_fetch(&json->refcount, 1)
#else
#define JSON_INTERNAL_INCREF(json) (++json->refcount)
#define JSON_INTERNAL_DECREF(json) (--json->refcount)
#endif

static JSON_INLINE json_t *json_incref(json_t *json) {
    if (json && json->refcount != (size_t)-1)
        JSON_INTERNAL_INCREF(json);
    return json;
}

/* do not call json_delete directly */
void json_delete(json_t *json);

static JSON_INLINE void json_decref(json_t *json) {
    if (json && json->refcount != (size_t)-1 && JSON_INTERNAL_DECREF(json) == 0)
        json_delete(json);
}

#if defined(__GNUC__) || defined(__clang__)
static JSON_INLINE void json_decrefp(json_t **json) {
    if (json) {
        json_decref(*json);
        *json = NULL;
    }
}

#define json_auto_t json_t __attribute__((cleanup(json_decrefp)))
#endif

/* error reporting */

#define JSON_ERROR_TEXT_LENGTH   160
#define JSON_ERROR_SOURCE_LENGTH 80

typedef struct json_error_t {
    int line;
    int column;
    int position;
    char source[JSON_ERROR_SOURCE_LENGTH];
    char text[JSON_ERROR_TEXT_LENGTH];
} json_error_t;

enum json_error_code {
    json_error_unknown,
    json_error_out_of_memory,
    json_error_stack_overflow,
    json_error_cannot_open_file,
    json_error_invalid_argument,
    json_error_invalid_utf8,
    json_error_premature_end_of_input,
    json_error_end_of_input_expected,
    json_error_invalid_syntax,
    json_error_invalid_format,
    json_error_wrong_type,
    json_error_null_character,
    json_error_null_value,
    json_error_null_byte_in_key,
    json_error_duplicate_key,
    json_error_numeric_overflow,
    json_error_item_not_found,
    json_error_index_out_of_range
};

static JSON_INLINE enum json_error_code json_error_code(const json_error_t *e) {
    return (enum json_error_code)e->text[JSON_ERROR_TEXT_LENGTH - 1];
}

/* getters, setters, manipulation */

void json_object_seed(size_t seed);
size_t json_object_size(const json_t *object);
json_t *json_object_get(const json_t *object, const char *key)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_object_getn(const json_t *object, const char *key, size_t key_len)
    JANSSON_ATTRS((warn_unused_result));
int json_object_set_new(json_t *object, const char *key, json_t *value);
int json_object_setn_new(json_t *object, const char *key, size_t key_len, json_t *value);
int json_object_set_new_nocheck(json_t *object, const char *key, json_t *value);
int json_object_setn_new_nocheck(json_t *object, const char *key, size_t key_len,
                                 json_t *value);
int json_object_del(json_t *object, const char *key);
int json_object_deln(json_t *object, const char *key, size_t key_len);
int json_object_clear(json_t *object);
int json_object_update(json_t *object, json_t *other);
int json_object_update_existing(json_t *object, json_t *other);
int json_object_update_missing(json_t *object, json_t *other);
int json_object_update_recursive(json_t *object, json_t *other);
void *json_object_iter(json_t *object);
void *json_object_iter_at(json_t *object, const char *key);
void *json_object_key_to_iter(const char *key);
void *json_object_iter_next(json_t *object, void *iter);
const char *json_object_iter_key(void *iter);
size_t json_object_iter_key_len(void *iter);
json_t *json_object_iter_value(void *iter);
int json_object_iter_set_new(json_t *object, void *iter, json_t *value);

#define json_object_foreach(object, key, value)                                          \
    for (key = json_object_iter_key(json_object_iter(object));                           \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(                                                     \
             json_object_iter_next(object, json_object_key_to_iter(key))))

#define json_object_keylen_foreach(object, key, key_len, value)                          \
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key));                \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(                                                     \
             json_object_iter_next(object, json_object_key_to_iter(key))),               \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key)))

#define json_object_foreach_safe(object, n, key, value)                                  \
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        n = json_object_iter_next(object, json_object_key_to_iter(key));                 \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(n),                                                  \
        n = json_object_iter_next(object, json_object_key_to_iter(key)))

#define json_object_keylen_foreach_safe(object, n, key, key_len, value)                  \
    for (key = json_object_iter_key(json_object_iter(object)),                           \
        n = json_object_iter_next(object, json_object_key_to_iter(key)),                 \
        key_len = json_object_iter_key_len(json_object_key_to_iter(key));                \
         key && (value = json_object_iter_value(json_object_key_to_iter(key)));          \
         key = json_object_iter_key(n), key_len = json_object_iter_key_len(n),           \
        n = json_object_iter_next(object, json_object_key_to_iter(key)))

#define json_array_foreach(array, index, value)                                          \
    for (index = 0;                                                                      \
         index < json_array_size(array) && (value = json_array_get(array, index));       \
         index++)

static JSON_INLINE int json_object_set(json_t *object, const char *key, json_t *value) {
    return json_object_set_new(object, key, json_incref(value));
}

static JSON_INLINE int json_object_setn(json_t *object, const char *key, size_t key_len,
                                        json_t *value) {
    return json_object_setn_new(object, key, key_len, json_incref(value));
}

static JSON_INLINE int json_object_set_nocheck(json_t *object, const char *key,
                                               json_t *value) {
    return json_object_set_new_nocheck(object, key, json_incref(value));
}

static JSON_INLINE int json_object_setn_nocheck(json_t *object, const char *key,
                                                size_t key_len, json_t *value) {
    return json_object_setn_new_nocheck(object, key, key_len, json_incref(value));
}

static JSON_INLINE int json_object_iter_set(json_t *object, void *iter, json_t *value) {
    return json_object_iter_set_new(object, iter, json_incref(value));
}

static JSON_INLINE int json_object_update_new(json_t *object, json_t *other) {
    int ret = json_object_update(object, other);
    json_decref(other);
    return ret;
}

static JSON_INLINE int json_object_update_existing_new(json_t *object, json_t *other) {
    int ret = json_object_update_existing(object, other);
    json_decref(other);
    return ret;
}

static JSON_INLINE int json_object_update_missing_new(json_t *object, json_t *other) {
    int ret = json_object_update_missing(object, other);
    json_decref(other);
    return ret;
}

size_t json_array_size(const json_t *array);
json_t *json_array_get(const json_t *array, size_t index)
    JANSSON_ATTRS((warn_unused_result));
int json_array_set_new(json_t *array, size_t index, json_t *value);
int json_array_append_new(json_t *array, json_t *value);
int json_array_insert_new(json_t *array, size_t index, json_t *value);
int json_array_remove(json_t *array, size_t index);
int json_array_clear(json_t *array);
int json_array_extend(json_t *array, json_t *other);

static JSON_INLINE int json_array_set(json_t *array, size_t ind, json_t *value) {
    return json_array_set_new(array, ind, json_incref(value));
}

static JSON_INLINE int json_array_append(json_t *array, json_t *value) {
    return json_array_append_new(array, json_incref(value));
}

static JSON_INLINE int json_array_insert(json_t *array, size_t ind, json_t *value) {
    return json_array_insert_new(array, ind, json_incref(value));
}

const char *json_string_value(const json_t *string);
size_t json_string_length(const json_t *string);
json_int_t json_integer_value(const json_t *integer);
double json_real_value(const json_t *real);
double json_number_value(const json_t *json);

int json_string_set(json_t *string, const char *value);
int json_string_setn(json_t *string, const char *value, size_t len);
int json_string_set_nocheck(json_t *string, const char *value);
int json_string_setn_nocheck(json_t *string, const char *value, size_t len);
int json_integer_set(json_t *integer, json_int_t value);
int json_real_set(json_t *real, double value);

/* pack, unpack */

json_t *json_pack(const char *fmt, ...) JANSSON_ATTRS((warn_unused_result));
json_t *json_pack_ex(json_error_t *error, size_t flags, const char *fmt, ...)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_vpack_ex(json_error_t *error, size_t flags, const char *fmt, va_list ap)
    JANSSON_ATTRS((warn_unused_result));

#define JSON_VALIDATE_ONLY 0x1
#define JSON_STRICT        0x2

int json_unpack(json_t *root, const char *fmt, ...);
int json_unpack_ex(json_t *root, json_error_t *error, size_t flags, const char *fmt, ...);
int json_vunpack_ex(json_t *root, json_error_t *error, size_t flags, const char *fmt,
                    va_list ap);

/* sprintf */

json_t *json_sprintf(const char *fmt, ...)
    JANSSON_ATTRS((warn_unused_result, format(printf, 1, 2)));
json_t *json_vsprintf(const char *fmt, va_list ap)
    JANSSON_ATTRS((warn_unused_result, format(printf, 1, 0)));

/* equality */

int json_equal(const json_t *value1, const json_t *value2);

/* copying */

json_t *json_copy(json_t *value) JANSSON_ATTRS((warn_unused_result));
json_t *json_deep_copy(const json_t *value) JANSSON_ATTRS((warn_unused_result));

/* decoding */

#define JSON_REJECT_DUPLICATES  0x1
#define JSON_DISABLE_EOF_CHECK  0x2
#define JSON_DECODE_ANY         0x4
#define JSON_DECODE_INT_AS_REAL 0x8
#define JSON_ALLOW_NUL          0x10

typedef size_t (*json_load_callback_t)(void *buffer, size_t buflen, void *data);

json_t *json_loads(const char *input, size_t flags, json_error_t *error)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_loadb(const char *buffer, size_t buflen, size_t flags, json_error_t *error)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_loadf(FILE *input, size_t flags, json_error_t *error)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_loadfd(int input, size_t flags, json_error_t *error)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_load_file(const char *path, size_t flags, json_error_t *error)
    JANSSON_ATTRS((warn_unused_result));
json_t *json_load_callback(json_load_callback_t callback, void *data, size_t flags,
                           json_error_t *error) JANSSON_ATTRS((warn_unused_result));

/* encoding */

#define JSON_MAX_INDENT        0x1F
#define JSON_INDENT(n)         ((n)&JSON_MAX_INDENT)
#define JSON_COMPACT           0x20
#define JSON_ENSURE_ASCII      0x40
#define JSON_SORT_KEYS         0x80
#define JSON_PRESERVE_ORDER    0x100
#define JSON_ENCODE_ANY        0x200
#define JSON_ESCAPE_SLASH      0x400
#define JSON_REAL_PRECISION(n) (((n)&0x1F) << 11)
#define JSON_EMBED             0x10000

typedef int (*json_dump_callback_t)(const char *buffer, size_t size, void *data);

char *json_dumps(const json_t *json, size_t flags) JANSSON_ATTRS((warn_unused_result));
size_t json_dumpb(const json_t *json, char *buffer, size_t size, size_t flags);
int json_dumpf(const json_t *json, FILE *output, size_t flags);
int json_dumpfd(const json_t *json, int output, size_t flags);
int json_dump_file(const json_t *json, const char *path, size_t flags);
int json_dump_callback(const json_t *json, json_dump_callback_t callback, void *data,
                       size_t flags);

/* custom memory allocation */

typedef void *(*json_malloc_t)(size_t);
typedef void (*json_free_t)(void *);

void json_set_alloc_funcs(json_malloc_t malloc_fn, json_free_t free_fn);
void json_get_alloc_funcs(json_malloc_t *malloc_fn, json_free_t *free_fn);

/* runtime version checking */

const char *jansson_version_str(void);
int jansson_version_cmp(int major, int minor, int micro);

#ifdef __cplusplus
}
#endif

#endif
```

---

Généré par [doxybook2](https://github.com/matusnovak/doxybook2) v1.4.0
