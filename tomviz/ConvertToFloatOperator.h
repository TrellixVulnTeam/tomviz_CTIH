/******************************************************************************

  This source file is part of the tomviz project.

  Copyright Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/
#ifndef tomvizConvertToFloatOperator_h
#define tomvizConvertToFloatOperator_h

#include "Operator.h"

namespace tomviz
{

class ConvertToFloatOperator : public Operator
{
  Q_OBJECT
  typedef Operator Superclass;

public:
  ConvertToFloatOperator(QObject *parent=nullptr);
  virtual ~ConvertToFloatOperator();

  QString label() const override { return "Convert to Float"; }
  QIcon icon() const override;
  Operator *clone() const override;
  bool serialize(pugi::xml_node& ns) const override;
  bool deserialize(const pugi::xml_node& ns) override;
  EditOperatorWidget *getEditorContents(QWidget* parent) override;
  bool hasCustomUI() const override { return false; }

protected:
  bool applyTransform(vtkDataObject *data) override;

private:
  Q_DISABLE_COPY(ConvertToFloatOperator)
};
}

#endif
