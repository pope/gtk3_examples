#include <glib/gprintf.h>
#include <gtk/gtk.h>
#include <stdlib.h>

static void clicked(GtkWidget* button, G_GNUC_UNUSED gpointer data) {
  g_printf("You clicked %s!\n", gtk_button_get_label(GTK_BUTTON(button)));
}

static GtkWidget* main_window() {
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "");

  // Box
  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_container_add(GTK_CONTAINER(window), box);

  // Bacon button
  GtkWidget* bacon_button = gtk_button_new_with_label("Bacon");
  g_signal_connect(bacon_button, "clicked", G_CALLBACK(clicked), NULL);
  gtk_box_pack_start(GTK_BOX(box), bacon_button, TRUE, TRUE, 0);

  // Tuna button
  GtkWidget* tuna_button = gtk_button_new_with_label("Tuna");
  g_signal_connect(tuna_button, "clicked", G_CALLBACK(clicked), NULL);
  gtk_box_pack_start(GTK_BOX(box), tuna_button, TRUE, TRUE, 0);

  return window;
}

int main(int argc, char** argv) {
  gtk_init(&argc, &argv);

  GtkWidget* window = main_window();
  g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}
