#include <gtk/gtk.h>
#include <stdlib.h>

static GtkWidget* main_window() {
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Cheeseburger Machine");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  GtkWidget* listbox = gtk_list_box_new();
  gtk_list_box_set_selection_mode(GTK_LIST_BOX(listbox), GTK_SELECTION_NONE);
  gtk_container_add(GTK_CONTAINER(window), listbox);

  // Re-use variables so we're not making row1, row2, and such.
  GtkWidget *row, *box, *label;

  // Checkbox
  row = gtk_list_box_row_new();
  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(row), box);
  label = gtk_label_new("Check if you love cheeseburgers:");
  GtkWidget* check = gtk_check_button_new();
  gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), check, TRUE, TRUE, 0);
  gtk_container_add(GTK_CONTAINER(listbox), row);

  // Toggle Switch
  row = gtk_list_box_row_new();
  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
  gtk_container_add(GTK_CONTAINER(row), box);
  label = gtk_label_new("Burger making machine`:");
  GtkWidget* switcher = gtk_switch_new();
  gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), switcher, TRUE, TRUE, 0);
  gtk_container_add(GTK_CONTAINER(listbox), row);

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
