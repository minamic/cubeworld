/*
 * Copyright 2010-2012 Scott MacDonald
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef SCOTT_MATH_CONFIG_H
#define SCOTT_MATH_CONFIG_H

#define MATH_TYPEDEFS
#define MATH_FUZZY_EQUALS
/* #undef MATH_DOUBLE */
#define MATH_DEBUG

/**
 * Defines the Scalar type, which is used by the math library to determine
 * the precision of a floating point value.
 */
#ifdef MATH_DOUBLE
    typedef double scalar_t;
#else
    typedef float scalar_t;
#endif

/**
 * Math assertion macro. Assertions in the mathlibrary use math_assert,
 * rather than assert. This allows us to selectively disable math
 * assertions and continue using assertions in the rest of the application.
 * By default, math_assert is only enabled when MATH_DEBUG_MODE is defined.
 */
#ifdef MATH_DEBUG
#   include <common/assert.h>
#   include <limits>
#   define MATH_ASSERT(expr,msg) CORE_ASSERT(expr,msg)
#   define SCOTT_NAN      std::numeric_limits<T>::signaling_NaN()
#else
#   define MATH_ASSERT(expr,msg) (static_cast<void>(0))
#   define SCOTT_NAN (static_cast<void>(0))
#endif

#endif
