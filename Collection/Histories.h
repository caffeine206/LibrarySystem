/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * Histories is an unindexed collection of history models.  It is
 * meant for keeping track of all the user histories, including information
 * such as when a user has checked out or returned books.  Histories includes
 * the functionality of being able to add a history to the collection.  
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 */

#ifndef __Histories_H
#define __Histories_H

#include "./UnIndexed.h"
#include "../Model/History.h"

class Histories : public UnIndexed {
  public:
    void append(History* model); // Add a history to the history collection
  protected:
};

#endif
