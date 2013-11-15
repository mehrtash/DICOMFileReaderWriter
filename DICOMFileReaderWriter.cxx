
#include "DICOMFileReaderWriterCLP.h"

// ITK includes
#include "itkImageSeriesReader.h"
#include "itkImageSeriesWriter.h"
#include "itkDICOMImageIO2.h"
#include "itkDICOMSeriesFileNames.h"
#include "itkImageFileWriter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkExtractImageFilter.h"
#include "itkShiftScaleImageFilter.h"
#include "itkGDCMImageIO.h"
#include "itkDCMTKImageIO.h"
#include "itkDCMTKSeriesFileNames.h"
#include "itkMetaDataObject.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkNumericSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include <vector>
#include "itksys/SystemTools.hxx"
#include "itkPluginUtilities.h"

namespace
{

}

int main(int argc, char* argv[])
{
  PARSE_ARGS;

  typedef itk::Image<unsigned short, 2>   Image2DType;
  typedef itk::ImageFileReader<Image2DType> Reader2DType;
  typedef itk::ImageFileWriter<Image2DType> Writer2DType;

  typedef itk::Image<unsigned short, 3>   Image3DType;
  typedef itk::ImageFileReader<Image3DType> Reader3DType;
  typedef itk::ImageFileWriter<Image3DType> Writer3DType;



  //GDCM Reader-Writer
  if( ioType == "GDCM" && imageDimension == "3")
  {
  Reader3DType::Pointer reader3DGDCM = Reader3DType::New();
  Writer3DType::Pointer writer3DGDCM = Writer3DType::New();
  reader3DGDCM->SetImageIO(itk::GDCMImageIO::New());
  reader3DGDCM->SetFileName(inputFile.c_str());
  writer3DGDCM->SetFileName(outputFile.c_str());

  try
  {
    reader3DGDCM->Update();
  }

  catch (itk::ExceptionObject & e)
  {
    std::cerr << "exception in file reader" << std::endl;
    std::cerr << e << std::endl;
    return EXIT_FAILURE;
  }

  writer3DGDCM->SetInput(reader3DGDCM->GetOutput());

  try
  {
    writer3DGDCM->Update();
  }

  catch (itk::ExceptionObject & e)
  {
    std::cerr << "exception in file writer" << std::endl;
    std::cerr << e << std::endl;
    return EXIT_FAILURE;
  }
  }
  else if( ioType == "GDCM" && imageDimension == "2")
  {
      Reader2DType::Pointer reader2DGDCM = Reader2DType::New();
      Writer2DType::Pointer writer2DGDCM = Writer2DType::New();
      reader2DGDCM->SetImageIO(itk::GDCMImageIO::New());
      reader2DGDCM->SetFileName(inputFile.c_str());
      writer2DGDCM->SetFileName(outputFile.c_str());

      try
      {
        reader2DGDCM->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file reader" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }

      writer2DGDCM->SetInput(reader2DGDCM->GetOutput());

      try
      {
        writer2DGDCM->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file writer" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }
  }

  //DCMTK Reader-Writer
  else if( ioType == "DCMTK" && imageDimension == "3")
  {

  }
  else if( ioType == "DCMTK" && imageDimension == "2")
  {

  }

  return EXIT_SUCCESS;
}
