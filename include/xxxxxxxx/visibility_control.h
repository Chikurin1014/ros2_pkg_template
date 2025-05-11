#ifndef XXXXXXXX__VISIBILITY_CONTROL_H_
#define XXXXXXXX__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define XXXXXXXX_EXPORT __attribute__ ((dllexport))
    #define XXXXXXXX_IMPORT __attribute__ ((dllimport))
  #else
    #define XXXXXXXX_EXPORT __declspec(dllexport)
    #define XXXXXXXX_IMPORT __declspec(dllimport)
  #endif
  #ifdef XXXXXXXX_BUILDING_LIBRARY
    #define XXXXXXXX_PUBLIC XXXXXXXX_EXPORT
  #else
    #define XXXXXXXX_PUBLIC XXXXXXXX_IMPORT
  #endif
  #define XXXXXXXX_PUBLIC_TYPE XXXXXXXX_PUBLIC
  #define XXXXXXXX_LOCAL
#else
  #define XXXXXXXX_EXPORT __attribute__ ((visibility("default")))
  #define XXXXXXXX_IMPORT
  #if __GNUC__ >= 4
    #define XXXXXXXX_PUBLIC __attribute__ ((visibility("default")))
    #define XXXXXXXX_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define XXXXXXXX_PUBLIC
    #define XXXXXXXX_LOCAL
  #endif
  #define XXXXXXXX_PUBLIC_TYPE
#endif

#endif  // XXXXXXXX__VISIBILITY_CONTROL_H_
