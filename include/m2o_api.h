/* Mafia 2 Online Server API header definitions */
/* generated on Fri Feb 23 2018 22:51:45 GMT+0200 (EET) */

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

#define M2O_PLUGIN_MAIN(m2o_api) M2O_DLL_EXPORT void m2o_plugin_main(m2o_api_vtable *m2o_api)

#if defined(__cplusplus)
extern "C" {
#endif

typedef union vec3_t {
    struct {
        float x;
        float y;
        float z;
    };

    float xyz[3];
} vec3_t;

typedef void (m2o_api_set_last_error)(unsigned int error);
typedef unsigned int (m2o_api_get_last_error)();
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
