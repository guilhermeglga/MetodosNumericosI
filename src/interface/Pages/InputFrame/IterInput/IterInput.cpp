#include "IterInput.h"

#include "../../../Widgets/Inputs/NumberEntry.h"
#include "../../../Widgets/Inputs/IntEntry.h"

void IterInput::render(){
    Page::render();

}

IterInput::IterInput(Rectangle bounds_, ControlFlow* flow_)
    :Page(bounds_, flow_)
{
    entries.n = 1;
    entries.epsilon = 1;
    entries.metodo = NEWTON_PADRAO_DER_CALC;
    
    //append_child(new NumberEntry({100, 100}));
    append_child(new IntEntry({100, 100}, 0, 100), []());
}

IterEntries IterInput::get_entries()
{
    return entries;
}
