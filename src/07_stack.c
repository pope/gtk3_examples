#include <gtk/gtk.h>
#include <stdlib.h>

static GtkWidget* main_window() {
  GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Switcher");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_add(GTK_CONTAINER(window), box);

  // Stack
  GtkWidget* main_area = gtk_stack_new();
  gtk_stack_set_transition_type(GTK_STACK(main_area),
                                GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
  gtk_stack_set_transition_duration(GTK_STACK(main_area), 2000);

  // Checkbox
  GtkWidget* check_button =
      gtk_check_button_new_with_label("Do not fn check me");
  gtk_stack_add_titled(GTK_STACK(main_area), check_button, "check_name",
                       "Check Box");

  // Label
  GtkWidget* label = gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label), "<big>OMG this text is huge!</big>");
  gtk_stack_add_titled(GTK_STACK(main_area), label, "label_name", "Big Label");

  // StackSwitcher
  GtkWidget* stack_switcher = gtk_stack_switcher_new();
  gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(stack_switcher),
                               GTK_STACK(main_area));

  gtk_box_pack_start(GTK_BOX(box), stack_switcher, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), main_area, TRUE, TRUE, 0);

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
