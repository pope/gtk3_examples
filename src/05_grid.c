#include <gtk/gtk.h>
#include <stdlib.h>

static GtkWidget* main_window() {
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Grid Example");

  GtkGrid* grid = GTK_GRID(gtk_grid_new());
  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));

  // Create a bunch of buttons
  GtkWidget* button1 = gtk_button_new_with_label("Button 1");
  GtkWidget* button2 = gtk_button_new_with_label("Button 2");
  GtkWidget* button3 = gtk_button_new_with_label("Button 3");
  GtkWidget* button4 = gtk_button_new_with_label("Button 4");
  GtkWidget* button5 = gtk_button_new_with_label("Button 5");
  GtkWidget* button6 = gtk_button_new_with_label("Button 6");

  gtk_container_add(GTK_CONTAINER(grid), button1);
  gtk_grid_attach(grid, button2, 1, 0, 2, 1);
  gtk_grid_attach_next_to(grid, button3, button1, GTK_POS_BOTTOM, 1, 2);
  gtk_grid_attach_next_to(grid, button4, button3, GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach(grid, button5, 1, 2, 1, 1);
  gtk_grid_attach_next_to(grid, button6, button5, GTK_POS_RIGHT, 1, 1);

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
