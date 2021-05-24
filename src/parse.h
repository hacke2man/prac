#ifndef __PARSE_H__
#define __PARSE_H__

#ifdef __cplusplus
extern "C" {
#endif

  struct Card {
    char * question;
    char * answer;
  };

  struct Card * MakeDeck(char * path);

#ifdef __cplusplus
}
#endif


#endif
