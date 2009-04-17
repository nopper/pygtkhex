
#ifndef __ghex_marshal_MARSHAL_H__
#define __ghex_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:OBJECT (ghex-marshal.list:1) */
extern void ghex_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* VOID:POINTER (ghex-marshal.list:2) */
#define ghex_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER

/* VOID:POINTER,BOOLEAN (ghex-marshal.list:3) */
extern void ghex_marshal_VOID__POINTER_BOOLEAN (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:VOID (ghex-marshal.list:4) */
#define ghex_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

G_END_DECLS

#endif /* __ghex_marshal_MARSHAL_H__ */

