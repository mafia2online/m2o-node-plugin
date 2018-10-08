/* Mafia 2 Online Server API header definitions */
/* Generated on Mon Oct 08 2018 17:41:35 GMT+0300 (EEST) */

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


// =======================================================================//
// !
// ! Main macro definitions
// !
// =======================================================================//

    #define M2O_NAME "Mafia 2 Online - Reborn"

    #define M2O_VERSION_MAJOR 1
    #define M2O_VERSION_MINOR 0
    #define M2O_VERSION_PATCH 0

    #define M2O_QUOTE_X(t) #t
    #define M2O_QUOTE(t) M2O_QUOTE_X(t)
    #define M2O_VERSION_CREATE(major, minor, patch) (((major)<<16) | ((minor)<<8) | (patch))
    #define M2O_VERSION_GET_MAJOR(version) (((version)>>16)&0xFF)
    #define M2O_VERSION_GET_MINOR(version) (((version)>>8)&0xFF)
    #define M2O_VERSION_GET_PATCH(version) ((version)&0xFF)

    #define M2O_VERSION_STRING M2O_QUOTE(M2O_VERSION_MAJOR) "." M2O_QUOTE(M2O_VERSION_MINOR) "." M2O_QUOTE(M2O_VERSION_PATCH)
    #define M2O_VERSION_NUMBER M2O_VERSION_CREATE(M2O_VERSION_MAJOR, M2O_VERSION_MINOR, M2O_VERSION_PATCH)
    #define M2O_VERSION_PRETTY M2O_NAME ". v" M2O_VERSION_STRING

    #define M2O_ENTITY_LIMIT 16000
    #define M2O_INVALID_ENTITY M2O_ENTITY_LIMIT


// =======================================================================//
// !
// ! Basic types
// !
// =======================================================================//

#ifndef M2O_API_DISABLE_VEC3

    typedef union m2o_vec3 {
        struct {
            float x;
            float y;
            float z;
        };

        float xyz[3];
    } m2o_vec3;

#endif // M2O_API_DISABLE_VEC3

    typedef enum {
        M2O_ERROR_NONE,
        M2O_UNDEFINED_ENTITY,
    } m2o_error;

// =======================================================================//
// !
// ! Plugins/events structs
// !
// =======================================================================//

    typedef enum m2o_event_type {
        M2O_EVENT_NONE,

        M2O_EVENT_PLUGIN_INIT,
        M2O_EVENT_PLUGIN_TICK,
        M2O_EVENT_PLUGIN_STOP,

        M2O_EVENT_SERVER_CONSOLE, /* TODO: not implemented */

        M2O_EVENT_PLAYER_CONNECT,
        M2O_EVENT_PLAYER_DISCONNECT,
        M2O_EVENT_PLAYER_NAME,
        M2O_EVENT_PLAYER_CHAT,  /* TODO: not implemented */

        M2O_EVENT_PED_WEAPON_CHANGE, /* TODO: not implemented */
        M2O_EVENT_PED_CAR_ENTER,
        M2O_EVENT_PED_CAR_EXIT,
        M2O_EVENT_PED_DEATH, /* TODO: not implemented */
        M2O_EVENT_PED_HEALTH_CHANGE, /* TODO: not implemented */

        M2O_EVENT_CUSTOM,
    } m2o_event_type;

    typedef enum m2o_event_result {
        M2O_EVENT_RESULT_NONE       = 0,
        M2O_EVENT_RESULT_REJECTED   = (1 << 0),
    } m2o_event_result;

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

    typedef void (m2o_callback)(const m2o_args *, m2o_event_result *result);

    typedef struct {
        const char *name;
        const char *author;
        unsigned int version;

        struct {
            m2o_callback *plugin_init;
            m2o_callback *plugin_tick;
            m2o_callback *plugin_stop;

            m2o_callback *server_console;

            m2o_callback *player_connect;
            m2o_callback *player_disconnect;
            m2o_callback *player_name;
            m2o_callback *player_chat;

            m2o_callback *ped_car_enter;
            m2o_callback *ped_car_exit;
            m2o_callback *ped_weapon_change;
            m2o_callback *ped_health_change;
            m2o_callback *ped_death;

            m2o_callback *custom_event;
        } callbacks;
    } m2o_plugin;


// =======================================================================//
// !
// ! Generated methods
// !
// =======================================================================//

typedef void (m2o_api_error_set)(m2o_error error);
typedef m2o_error (m2o_api_error_get)();
typedef void (m2o_api_event_trigger)(m2o_event_type type, const m2o_args* args);;
typedef void (m2o_api_event_trigger_result)(m2o_event_type type, const m2o_args* args, m2o_event_result *result);;
typedef void (m2o_api_args_init)(m2o_args *arg);
typedef void (m2o_api_args_free)(m2o_args *arg);
typedef size_t (m2o_api_args_size)(m2o_args *arg);
typedef m2o_arg_value *(m2o_api_args_get)(m2o_args *arg, size_t i);
typedef void (m2o_api_args_push_string)(m2o_args *arg, const char *string);
typedef void (m2o_api_args_push_integer)(m2o_args *arg, long integer);
typedef void (m2o_api_args_push_real)(m2o_args *arg, double real);
typedef void (m2o_api_args_push_pointer)(m2o_args *arg, void *pointer);
typedef unsigned int (m2o_api_vehicle_create)();
typedef bool (m2o_api_vehicle_destroy)(unsigned int vehicleid);
typedef bool (m2o_api_vehicle_position_set)(unsigned int vehicleid, m2o_vec3_t position);
typedef m2o_vec3_t (m2o_api_vehicle_position_get)(unsigned int vehicleid);
typedef bool (m2o_api_player_kick)(unsigned int playerid);
typedef unsigned int (m2o_api_ped_create)();
typedef bool (m2o_api_ped_destroy)(unsigned int pedid);
typedef bool (m2o_api_ped_position_set)(unsigned int pedid, m2o_vec3 position);
typedef m2o_vec3 (m2o_api_ped_position_get)(unsigned int pedid);

typedef struct m2o_api_vtable {
    m2o_api_error_set *error_set;
    m2o_api_error_get *error_get;
    m2o_api_event_trigger *event_trigger;
    m2o_api_event_trigger_result *event_trigger_result;
    m2o_api_args_init *args_init;
    m2o_api_args_free *args_free;
    m2o_api_args_size *args_size;
    m2o_api_args_get *args_get;
    m2o_api_args_push_string *args_push_string;
    m2o_api_args_push_integer *args_push_integer;
    m2o_api_args_push_real *args_push_real;
    m2o_api_args_push_pointer *args_push_pointer;
    m2o_api_vehicle_create *vehicle_create;
    m2o_api_vehicle_destroy *vehicle_destroy;
    m2o_api_vehicle_position_set *vehicle_position_set;
    m2o_api_vehicle_position_get *vehicle_position_get;
    m2o_api_player_kick *player_kick;
    m2o_api_ped_create *ped_create;
    m2o_api_ped_destroy *ped_destroy;
    m2o_api_ped_position_set *ped_position_set;
    m2o_api_ped_position_get *ped_position_get;
} m2o_api_vtable;

#if defined(__cplusplus)
}
#endif
#endif // M2O_API_H
