
#ifndef _MATHLIB_H_
#define _MATHLIB_H_

#include <stddef.h>

#define ML_PI_LD  3.1415926535897932384626433L
#define ML_PI_D   3.14159265358979323846
#define ML_PI_F   3.14159265358979f

#ifdef __cplusplus
extern "C"{
#endif

#ifndef MLLIB
    #ifdef MLLIB_STATIC
        #define MLLIB static
    #else
        #define MLLIB extern
    #endif
#endif

/* Pi */
#define ML_PI(x) _Generic((x),                 \
    float:          ML_PI_F,                   \
    double:         ML_PI_D,                   \
    long double:    ML_PI_LD                   \
)
#define ml_sqr(x) _Generic((x), \
    float:          ml_sqr_f,   \
    double:         ml_sqr_d,   \
    long double:    ml_sqr_ld,  \
    int:            ml_sqri,    \
    long int:       ml_sqri,    \
    default:        ml_sqr_d    \
)(x)
#define ml_cube(x) _Generic((x),\
    float:          ml_cube_f,  \
    double:         ml_cube_d,  \
    long double:    ml_cube_ld, \
    int:            ml_cubei,   \
    long int:       ml_cubei,   \
    default:        ml_cube_d   \
)(x)

/* Vectors*/
/* 2D */
typedef struct{
    float x, y;
}ml_Vec2;
/* 3D */
typedef struct{
    float x, y, z;
}ml_Vec3;

/* Containers */
typedef struct {
    ml_Vec2 *data;
    size_t size;
    size_t capacity;
} ml_Vec2List;
typedef struct {
    ml_Vec3 *data;
    size_t size;
    size_t capacity;
} ml_Vec3List;

static inline float ml_sqr_f(float x)                                                    { return x * x ; }
static inline double ml_sqr_d(double x)                                                  { return x * x ; }
static inline long double ml_sqr_ld(long double x)                                       { return x * x ; }
static inline int ml_sqri(int x)                                                         { return x * x ; }

static inline float ml_cube_f(float x)                                                   { return x * x * x ; }
static inline double ml_cube_d(double x)                                                 { return x * x * x ; }
static inline long double ml_cube_ld(long double x)                                      { return x * x * x ; }
static inline int ml_cubei(int x)                                                        { return x * x * x ; }

static inline float ml_clamp_f(float val, float min, float max)                          { return (val < min) ? min : (val > max) ? max : val ;}
static inline double ml_clamp_d(double val, double min, double max)                      { return (val < min) ? min : (val > max) ? max : val ;}
static inline long double ml_clamp_ld(long double val, long double min, long double max) { return (val < min) ? min : (val > max) ? max : val ;}
static inline int ml_clampi(int val, int min, int max)                                   { return (val < min) ? min : (val > max) ? max : val ;}

static inline float ml_deg2rad_f(float d)                                                { return ((d) * ML_PI_F) / 180.0f ;}
static inline double ml_deg2rad_d(double d)                                              { return ((d) * ML_PI_D) / 180.0 ;}
static inline long double ml_deg2rad_ld(long double d)                                   { return ((d) * ML_PI_LD) / 180.0L ;}

static inline float ml_rad2deg_f(float r)                                                { return ((r) * 180.0f) / ML_PI_F ;}
static inline double ml_rad2deg_d(double r)                                              { return ((r) * 180.0) / ML_PI_D ;}
static inline long double ml_rad2deg_ld(long double r)                                   { return ((r) * 180.0L) / ML_PI_LD ;}

static inline float ml_area_of_triangle_f(float b, float h)                              { return 0.5f * b * h ;}
static inline double ml_area_of_triangle_d(double b, double h)                           { return 0.5 * b * h ;}
static inline long double ml_area_of_triangle_ld(long double b, long double h)           { return 0.5L * b * h ;}

static inline float ml_area_of_circle_f(float r)                                         { return ML_PI_F * (ml_sqr_f(r));}
static inline double ml_area_of_circle_d(double r)                                       { return ML_PI_D * (ml_sqr_d(r));}
static inline long double ml_area_of_circle_ld(long double r)                            { return ML_PI_LD * (ml_sqr_ld(r));}

static inline float ml_absf(float x)                                                     { return (x < 0)? -x : x ;}
static inline float ml_absd(double x)                                                    { return (x < 0)? -x : x ;}
static inline long double ml_absld(long double x)                                        { return (x < 0)? -x : x ;}
static inline int ml_absi(int x)                                                         { return (x < 0)? -x : x ;}



MLLIB void ml_veclist2_push(ml_Vec2List *l, ml_Vec2 point);
MLLIB void ml_veclist3_push(ml_Vec3List *l, ml_Vec3 point);


/* Generics */

#define ml_clamp(val, min, max) _Generic((val),\
    float:          ml_clamp_f,                \
    double:         ml_clamp_d,                \
    long double:    ml_clamp_ld,               \
    int:            ml_clampi,                 \
    long int:       ml_clampi,                 \
    default:        ml_clamp_d                 \
)(val, min, max)
#define ml_deg2rad(d) _Generic((d),            \
    float:          ml_deg2rad_f,              \
    double:         ml_deg2rad_d,              \
    long double:    ml_deg2rad_ld,             \
    default:        ml_deg2rad_d               \
)(d)
#define ml_rad2deg(r) _Generic((r),            \
    float:          ml_rad2deg_f,              \
    double:         ml_rad2deg_d,              \
    long double:    ml_rad2deg_ld,             \
    default:        ml_rad2deg_d               \
)(r)
#define ml_area_of_triangle(b, h) _Generic((b) + (h),\
    float:          ml_area_of_triangle_f,           \
    double:         ml_area_of_triangle_d,           \
    long double:    ml_area_of_triangle_ld,          \
    default:        ml_area_of_triangle_d            \
)(b, h)
#define ml_area_of_circle(r) _Generic((r),           \
    float:          ml_area_of_circle_f,             \
    double:         ml_area_of_circle_d,             \
    long double:    ml_area_of_circle_ld,            \
    default:        ml_area_of_circle_d              \
)(r)
#define ml_abs(x) _Generic((x),             \
    float:          ml_absf,                \
    double:         ml_absd,                \
    long double:    ml_absld,               \
    int:            ml_absi,                \
    default:        ml_absd                 \
)(x)
#define ml_veclist_push(list, point) _Generic((list),             \
    ml_Vec2List*:          ml_veclist2_push,                \
    ml_Vec3List*:          ml_veclist3_push               \
)(list, point)


#ifdef __cplusplus
}
#endif

#endif  // END _MATHLIB_H

// ----------------------------------
// IMPLEMENTATION SECTION
// ----------------------------------
//
#ifdef ML_LIB_IMPLEMENTATION

#include <stdlib.h>
#include <stdio.h>

MLLIB void ml_veclist2_push(ml_Vec2List *l, ml_Vec2 point){
    if(l->capacity == 0){
        l->capacity = 4;
        l->data = malloc(sizeof(ml_Vec2) * l->capacity);
    }
    if(l->size == l->capacity){
        l->capacity *=2;
        void *temp = realloc(l->data, sizeof(ml_Vec2) * l->capacity);
        if(!temp){
            fprintf(stderr, "Ran out of memory!");
            exit(1);
        }
        l->data = (ml_Vec2*)temp;
    }
    l->data[l->size++] = point;
}
MLLIB void ml_veclist3_push(ml_Vec3List *l, ml_Vec3 point){
    if(l->capacity == 0){
        l->capacity = 4;
        l->data = malloc(sizeof(ml_Vec2) * l->capacity);
    }
    if(l->size == l->capacity){
        l->capacity *=2;
        void *temp = realloc(l->data, sizeof(ml_Vec2) * l->capacity);
        if(!temp){
            fprintf(stderr, "Ran out of memory!");
            exit(1);
        }
        l->data = (ml_Vec3*)temp;
    }
    l->data[l->size++] = point;
}



#endif
