#ifndef SAMPLE_PACKAGE__VISIBILITY_CONTROL_H_
#define SAMPLE_PACKAGE__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define SAMPLE_PACKAGE_EXPORT __attribute__((dllexport))
#define SAMPLE_PACKAGE_IMPORT __attribute__((dllimport))
#else
#define SAMPLE_PACKAGE_EXPORT __declspec(dllexport)
#define SAMPLE_PACKAGE_IMPORT __declspec(dllimport)
#endif
#ifdef SAMPLE_PACKAGE_BUILDING_LIBRARY
#define SAMPLE_PACKAGE_PUBLIC SAMPLE_PACKAGE_EXPORT
#else
#define SAMPLE_PACKAGE_PUBLIC SAMPLE_PACKAGE_IMPORT
#endif
#define SAMPLE_PACKAGE_PUBLIC_TYPE SAMPLE_PACKAGE_PUBLIC
#define SAMPLE_PACKAGE_LOCAL
#else
#define SAMPLE_PACKAGE_EXPORT __attribute__((visibility("default")))
#define SAMPLE_PACKAGE_IMPORT
#if __GNUC__ >= 4
#define SAMPLE_PACKAGE_PUBLIC __attribute__((visibility("default")))
#define SAMPLE_PACKAGE_LOCAL __attribute__((visibility("hidden")))
#else
#define SAMPLE_PACKAGE_PUBLIC
#define SAMPLE_PACKAGE_LOCAL
#endif
#define SAMPLE_PACKAGE_PUBLIC_TYPE
#endif

#endif  // SAMPLE_PACKAGE__VISIBILITY_CONTROL_H_
