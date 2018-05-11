/* Mafia 2 Online Server API header definitions */
/* Generated on Fri May 11 2018 18:05:39 GMT+0300 (EEST) */

#ifndef M2O_API_H
#define M2O_API_H

#if defined(__cplusplus)
#define M2O_EXTERN extern "C"
#else
#define M2O_EXTERN extern
#endif

#if defined(_WIN32)
#define M2O_DLL_EXPORT M2O_EXTERN __declspec(dllexport)
#else
#define M2O_DLL_EXPORT M2O_EXTERN __attribute__((visibility("default")))
#endif

#define M2O_PLUGIN_MAIN(API, PLUGIN) M2O_DLL_EXPORT void m2o_plugin_main(const m2o_api_vtable *API, m2o_plugin *PLUGIN)

#if defined(__cplusplus)
extern "C" {
#endif

/* definitions */

#define M2O_VERSION_CREATE(major, minor, patch) (((major)<<16) | ((minor)<<8) | (patch))
#define M2O_VERSION_GET_MAJOR(version) (((version)>>16)&0xFF)
#define M2O_VERSION_GET_MINOR(version) (((version)>>8)&0xFF)
#define M2O_VERSION_GET_PATCH(version) ((version)&0xFF)

typedef union vec3_t {
    struct {
        float x;
        float y;
        float z;
    };

    float xyz[3];
} vec3_t;

typedef enum {
    M2O_ERROR_NONE,
    M2O_UNDEFINED_ENTITY,
} m2o_error;

typedef enum m2o_arg_type {
    M2O_ARG_POINTER,
    M2O_ARG_STRING,
    M2O_ARG_INTEGER,
    M2O_ARG_REAL,
} m2o_arg_type;

typedef struct m2o_arg_value {
    m2o_arg_type type;
    size_t size;

    union {
        void *pointer;
        char *string;
        long integer;
        double real;
    };
} m2o_arg_value;

typedef struct m2o_args {
    m2o_arg_value* values;
    size_t size;
} m2o_args;

typedef void (m2o_callback)(m2o_args *);
typedef void (m2o_event_callback)(const char *, m2o_args *);

typedef struct {
    const char *name;
    const char *author;
    unsigned int version;

    struct {
        m2o_callback *plugin_init;
        m2o_callback *plugin_tick;
        m2o_callback *plugin_stop;
        m2o_callback *player_connect;
        m2o_callback *player_disconnect;
        m2o_callback *player_message;
        m2o_event_callback *event_trigger;
    } callbacks;
} m2o_plugin;


/* public methods */
typedef void (m2o_api_set_last_error)(m2o_error error);
typedef m2o_error (m2o_api_get_last_error)();
typedef void (m2o_api_args_init)(m2o_args *arg);
typedef void (m2o_api_args_free)(m2o_args *arg);
typedef size_t (m2o_api_args_size)(m2o_args *arg);
typedef m2o_arg_value *(m2o_api_args_get)(m2o_args *arg, size_t i);
typedef void (m2o_api_args_push_string)(m2o_args *arg, const char *string);
typedef void (m2o_api_args_push_integer)(m2o_args *arg, long integer);
typedef void (m2o_api_args_push_real)(m2o_args *arg, double real);
typedef void (m2o_api_args_push_pointer)(m2o_args *arg, void *pointer);
typedef void (m2o_api_event_trigger)(char* name, m2o_args* args);
typedef unsigned int (m2o_api_vehicle_create)();
typedef bool (m2o_api_vehicle_destroy)(unsigned int vehicleid);
typedef bool (m2o_api_vehicle_position_set)(unsigned int vehicleid, vec3_t position);
typedef vec3_t (m2o_api_vehicle_position_get)(unsigned int vehicleid);
typedef unsigned int (m2o_api_ped_create)();
typedef bool (m2o_api_ped_destroy)(unsigned int pedid);
typedef bool (m2o_api_ped_position_set)(unsigned int pedid, vec3_t position);
typedef vec3_t (m2o_api_ped_position_get)(unsigned int pedid);

typedef struct m2o_api_vtable {
    m2o_api_set_last_error *set_last_error;
    m2o_api_get_last_error *get_last_error;
    m2o_api_args_init *args_init;
    m2o_api_args_free *args_free;
    m2o_api_args_size *args_size;
    m2o_api_args_get *args_get;
    m2o_api_args_push_string *args_push_string;
    m2o_api_args_push_integer *args_push_integer;
    m2o_api_args_push_real *args_push_real;
    m2o_api_args_push_pointer *args_push_pointer;
    m2o_api_event_trigger *event_trigger;
    m2o_api_vehicle_create *vehicle_create;
    m2o_api_vehicle_destroy *vehicle_destroy;
    m2o_api_vehicle_position_set *vehicle_position_set;
    m2o_api_vehicle_position_get *vehicle_position_get;
    m2o_api_ped_create *ped_create;
    m2o_api_ped_destroy *ped_destroy;
    m2o_api_ped_position_set *ped_position_set;
    m2o_api_ped_position_get *ped_position_get;
} m2o_api_vtable;

#if defined(__cplusplus)
}
#endif
#endif // M2O_API_H
