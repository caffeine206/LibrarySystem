/**
 * Programming Assignment #5 Final Project<br>
 * Sota Ogo, Derek Willms CSS 343, Winter 2014 on 3/21/2014<br>
 *
 * <p>
 * 
 *
 * @author      Sota Ogo, Derek Willms
 * @since       1.0
 * @version     1.0
 *
 * Histories is an unindexed collection of history models.  It is
 * meant for keeping track of all the user histories, including information
 * such as when a user has checked out or returned books.  Histories includes
 * the functionality of being able to add a history to the collection.  
 */

#include "./Histories.h"

void Histories::append(History* history) 
// Add a history to the history collection
{
    // Call superclass function
    UnIndexed::append(history);
}
