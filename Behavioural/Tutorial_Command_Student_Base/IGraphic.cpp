#include "IGraphic.h"


void IGraphic::SetRectangle(Rectangle r) { rect = r; }
const Rectangle& IGraphic::GetRectangle() const { return rect; }

IGraphic::~IGraphic() {}
