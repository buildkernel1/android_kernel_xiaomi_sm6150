// SPDX-License-Identifier: GPL-2.0
/*
 * Taken from:
 *  linux/lib/string.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */

#include <linux/types.h>
#include <linux/string.h>

#ifdef CONFIG_EFI_STUB

#ifndef __HAVE_ARCH_STRRCHR
char *strrchr(const char *s, int c)
{
    const char *p = s + strlen(s);
    do {
        if (*p == (char)c)
            return (char *)p;
    } while (--p >= s);
    return NULL;
}
#endif

#ifndef __HAVE_ARCH_STRSTR
char *strstr(const char *s1, const char *s2)
{
    size_t l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;
    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }
    return NULL;
}
#endif

#ifndef __HAVE_ARCH_STRNCMP
int strncmp(const char *cs, const char *ct, size_t count)
{
    unsigned char c1, c2;

    while (count) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (!c1)
            break;
        count--;
    }
    return 0;
}
#endif

#endif /* CONFIG_EFI_STUB */

