#include <stdio.h>
#include <stdbool.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "gui_engine.h"
#include "example-theme.h"

TTF_Font *ttfFontB = NULL;
TTF_Font *ttfFontR = NULL;
int ttfCharW;
int ttfCharH;
int retval;
g_widget *ddlist = NULL;

static void die(const char *message)
{
  fprintf(stderr, "error: %s\n", message);
  exit(EXIT_FAILURE);
}

static SDL_Surface *initSDL(void)
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    die("failed to initialize SDL");
  }
  atexit(SDL_Quit);

  SDL_Surface *screenSurface = SDL_SetVideoMode(800, 600, 16, SDL_SWSURFACE);
  if(screenSurface == NULL)
  {
    die("failed to open SDL window");
  }
  
  //Initialize SDL_ttf
  if( TTF_Init() == -1 )
  {
    die("failed to initialize TTF");
  }

  SDL_WM_SetCaption("GUI engine demo", NULL);

  return screenSurface;
}

static void buttonCallback(const g_event *event,
                           g_widget *widget,
                           void *user_data)
{
  //g_widget *input_box = user_data;

  //if(event->type == G_CLICK_LEFT)
  //{
    //strcpy(widget->window->title, input_box->input.text);
 //printf("DDLIST ITEM: %d\n", ddlist->drop_down.current_item);
 printf("TEST OUT\n");
 fflush(stdout);
  //}
}

static void ddlistCallback(const g_event *event, g_widget *widget, void *user_data)
{
  //if(event->type == G_CLICK_LEFT)
  //{
 //printf("DDLIST ITEM: %d", widget->drop_down.current_item);
 //fflush(stdout);
  //}
}

static void checkboxCallback(const g_event *event,
                             g_widget *widget,
                             void *user_data)
{
  g_widget *input_box = user_data;

  if(event->type == G_CLICK_LEFT)
  {
    input_box->input.flags.hide_text = widget->check.state;
  }
}

static g_window *createDemoWindow(int x, int y)
{
  g_window *window = g_create_window(x, y, 360, 230, "EasyOS");
  window->flags.close_button = 0;

  /* Attach text input elements. A width/height of 0 will cause the widget
     to fit by expanding to the right/bottom. */
  /*g_attach_text(window, 0, 0, 0, 0, "Insert window title:");
  g_widget *input_box = g_attach_input_box(window, 0, 25, 0, G_INPUT_BOX_H);*/

  /* Impose limits to input. */
  //input_box->input.limit = 20;
  /* input_box->input.flags.numbers = 0; */
  /* input_box->input.flags.special_chars = 0; */

  g_widget *button = g_attach_button(window, window->w/2 - 18, 190, "OK");
  button->event_function = buttonCallback;
  //button->event_data = input_box;

  /* Attach checkboxes. */
  /*g_attach_text(window, 30, 100, 0, 0, "Hide input");
  g_widget *checkbox = g_attach_check_box(window, 0, 98);
  checkbox->event_function = checkboxCallback;
  checkbox->event_data = input_box;

  g_attach_text(window, 30, 125, 0, 0, "Checkbox 2");
  g_attach_check_box(window, 0, 123);

  g_attach_text(window, 30, 150, 0, 0, "Checkbox 3");
  g_attach_check_box(window, 0, 148);*/

  /* Attach drop-down menu. */
  /*g_attach_text(window, window->w - 210, 65, 0, 0, "Choose your language:");*/
  g_attach_text(window, ttfCharW*4, 14, 0, 0, "Choose your language:");
  g_attach_text(window, ttfCharW*10, 34, 0, 0, "Vælg dit sprog:");
  g_attach_text(window, ttfCharW*5, 54, 0, 0, "Wähle deine Sprache:");
  g_attach_text(window, ttfCharW*9, 74, 0, 0, "Elige tu idioma:");
  g_attach_text(window, 0, 94, 0, 0, "Choisissez votre langue:");
  g_attach_text(window, ttfCharW*4, 114, 0, 0, "Scegli la tua LINGUA:");
  g_attach_text(window, ttfCharW*6, 134, 0, 0, "Wybierz swój język:");
  g_attach_text(window, ttfCharW*6, 154, 0, 0, "Escolha seu idioma:");

  /*da Vælg dit sprog:  de Wähle deine Sprache:  es Elige tu idioma:
   fr Choisissez votre langue:  it Scegli la tua LINGUA:  pl Wybierz swój język:
   pt Escolha seu idioma: */
  
  ddlist = g_attach_drop_down_list(window, 220, 20, 128,
    "en English\nda dansk\nde Deutsch\nes español\nfr Français\nit Italiano\npl Polski\npt Português");
  ddlist->event_function = ddlistCallback;

  /* Attach label with pop-up window. */
  /*g_widget *label = g_attach_text(window, window->w - 140, 250, 0,
                                  G_CHAR_H, "move mouse here");
  label->pop_up = g_create_pop_up_window(165, 80);
  g_attach_text(label->pop_up, 25, 15, 0, 0, "example pop-up");
  g_attach_input_box(label->pop_up, 0, 35, 0, 0);*/

  /* Attach slider. */
  /*g_attach_slider_h(window, 0, window->h - 20, 0, 0.5, 1.0);*/

  return window;
}

int main(void)
{
  SDL_Surface *screenSurface = initSDL();

  /* Initialize GUI. */
  if(g_init_everything() == 0)
  {
    SDL_FreeSurface(screenSurface);
    die("failed to initialize GUI engine");
  }
  
  /*BK*/
  ttfFontB = TTF_OpenFont("/usr/share/fonts/TTF/RobotoMono-Bold.ttf", 14);
  if( ttfFontB == NULL ) die("failed to load ttf font");
  retval = TTF_SizeText(ttfFontB, " ", &ttfCharW, &ttfCharH);
  if (retval == -1) {
    TTF_CloseFont(ttfFontB);
    die("failed to obtain ttf glyph metrics");
  }
  ttfFontR = TTF_OpenFont("/usr/share/fonts/TTF/RobotoMono-Regular.ttf", 14);
  
  /* Set the global default theme. This will only affect windows/widgets
     created after this call. */
  setExampleTheme();

  g_window *first_window = createDemoWindow(200, 150);

  //createDemoWindow(50, 50);

  g_raise_window(first_window);

  /* Main loop. */
  bool running = true;
  while(running)
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
      if(event.type == SDL_KEYDOWN)
      {
        if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
      }
    }

    /* Clear screenSurface. */
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

    /* Draw GUI. */
    g_draw_everything(screenSurface);

    /* Update screenSurface and keep framerate. */
    SDL_Flip(screenSurface);
    SDL_Delay(16);
  }

  SDL_FreeSurface(screenSurface);
  TTF_CloseFont(ttfFontB);
  TTF_CloseFont(ttfFontR);
  TTF_Quit();

  /* The GUI engine will cleanup itself atexit. */
}
