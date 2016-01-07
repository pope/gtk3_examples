#include <glib/gprintf.h>
#include <gtk/gtk.h>
#include <stdlib.h>

static void button_clicked(G_GNUC_UNUSED GtkWidget* button,
                           G_GNUC_UNUSED gpointer data) {
  g_printf("Gametime\n");
}

static GtkWidget* main_window() {
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Button Clicker 2.0");

  GtkWidget* button = gtk_button_new_with_label("Click here!");
  g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
  gtk_container_add(GTK_CONTAINER(window), button);

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
