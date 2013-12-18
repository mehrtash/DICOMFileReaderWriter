
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

  typedef itk::Image<unsigned short, 4>   Image4DType;
  typedef itk::ImageFileReader<Image4DType> Reader4DType;
  typedef itk::ImageFileWriter<Image4DType> Writer4DType;


  //GDCM Reader-Writer 3D
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
  // GDCM 2D
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
  // GDCM 4D
  else if( ioType == "GDCM" && imageDimension == "4")
  {
      Reader4DType::Pointer reader4DGDCM = Reader4DType::New();
      Writer4DType::Pointer writer4DGDCM = Writer4DType::New();
      reader4DGDCM->SetImageIO(itk::GDCMImageIO::New());
      reader4DGDCM->SetFileName(inputFile.c_str());
      writer4DGDCM->SetFileName(outputFile.c_str());

      try
      {
        reader4DGDCM->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file reader" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }

      writer4DGDCM->SetInput(reader4DGDCM->GetOutput());

      try
      {
        writer4DGDCM->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file writer" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }
  }
  //DCMTK Reader-Writer 3D
  else if( ioType == "DCMTK" && imageDimension == "3")
  {
    Reader3DType::Pointer reader3DDCMTK = Reader3DType::New();
    Writer3DType::Pointer writer3DCMTK = Writer3DType::New();
    reader3DDCMTK->SetImageIO(itk::DCMTKImageIO::New());
    reader3DDCMTK->SetFileName(inputFile.c_str());
    writer3DCMTK->SetFileName(outputFile.c_str());

    try
    {
    reader3DDCMTK->Update();
    }

    catch (itk::ExceptionObject & e)
    {
      std::cerr << "exception in file reader" << std::endl;
      std::cerr << e << std::endl;
      return EXIT_FAILURE;
    }

    writer3DCMTK->SetInput(reader3DDCMTK->GetOutput());

    try
    {
      writer3DCMTK->Update();
    }

    catch (itk::ExceptionObject & e)
    {
      std::cerr << "exception in file writer" << std::endl;
      std::cerr << e << std::endl;
      return EXIT_FAILURE;
    }
  }
  else if( ioType == "DCMTK" && imageDimension == "2")
  {
    Reader2DType::Pointer reader2DDCMTK = Reader2DType::New();
    Writer2DType::Pointer writer2DCMTK = Writer2DType::New();
    reader2DDCMTK->SetImageIO(itk::DCMTKImageIO::New());
    reader2DDCMTK->SetFileName(inputFile.c_str());
    writer2DCMTK->SetFileName(outputFile.c_str());

    try
    {
    reader2DDCMTK->Update();
    }

    catch (itk::ExceptionObject & e)
    {
      std::cerr << "exception in file reader" << std::endl;
      std::cerr << e << std::endl;
      return EXIT_FAILURE;
    }

    writer2DCMTK->SetInput(reader2DDCMTK->GetOutput());

    try
    {
      writer2DCMTK->Update();
    }

    catch (itk::ExceptionObject & e)
    {
      std::cerr << "exception in file writer" << std::endl;
      std::cerr << e << std::endl;
      return EXIT_FAILURE;
    }
  }
  // DCMTK 4D
  else if( ioType == "DCMTK" && imageDimension == "4")
  {
      Reader4DType::Pointer reader4DDCMTK = Reader4DType::New();
      Writer4DType::Pointer writer4DDCMTK = Writer4DType::New();
      reader4DDCMTK->SetImageIO(itk::DCMTKImageIO::New());
      reader4DDCMTK->SetFileName(inputFile.c_str());
      writer4DDCMTK->SetFileName(outputFile.c_str());

      try
      {
        reader4DDCMTK->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file reader" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }

      writer4DDCMTK->SetInput(reader4DDCMTK->GetOutput());

      try
      {
        writer4DDCMTK->Update();
      }

      catch (itk::ExceptionObject & e)
      {
        std::cerr << "exception in file writer" << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
      }
  }
  return EXIT_SUCCESS;
}
