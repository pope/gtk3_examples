#include <glib/gprintf.h>
#include <gtk/gtk.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  gtk_init(&argc, &argv);

  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  GtkWidget* label = gtk_label_new("OMG I think thenewboston is awesome!");
  gtk_label_set_angle(GTK_LABEL(label), 30.0);
  gtk_widget_set_halign(label, GTK_ALIGN_END);
  gtk_container_add(GTK_CONTAINER(window), label);

  GValue value = G_VALUE_INIT;
  g_value_init(&value, G_TYPE_STRING);
  g_object_get_property(G_OBJECT(label), "angle", &value);
  g_printf("%s\n", g_value_get_string(&value));
  // Or, get it via a method call.
  // g_printf("%f\n", gtk_label_get_angle(GTK_LABEL(label)));

  g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}
