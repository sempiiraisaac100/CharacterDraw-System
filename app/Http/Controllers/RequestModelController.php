<?php

namespace App\Http\Controllers;

use App\Http\Requests\CreateRequestModelRequest;
use App\Http\Requests\UpdateRequestModelRequest;
use App\Repositories\RequestModelRepository;
use App\Http\Controllers\AppBaseController;
use Illuminate\Http\Request;
use Flash;
use Response;

class RequestModelController extends AppBaseController
{
    /** @var RequestModelRepository $requestModelRepository*/
    private $requestModelRepository;

    public function __construct(RequestModelRepository $requestModelRepo)
    {
        $this->requestModelRepository = $requestModelRepo;
    }

    /**
     * Display a listing of the RequestModel.
     *
     * @param Request $request
     *
     * @return Response
     */
    public function index(Request $request)
    {
        $requestModels = $this->requestModelRepository->all();

        return view('request_models.index')
            ->with('requestModels', $requestModels);
    }

    /**
     * Show the form for creating a new RequestModel.
     *
     * @return Response
     */
    public function create()
    {
        return view('request_models.create');
    }

    /**
     * Store a newly created RequestModel in storage.
     *
     * @param CreateRequestModelRequest $request
     *
     * @return Response
     */
    public function store(CreateRequestModelRequest $request)
    {
        $input = $request->all();

        $requestModel = $this->requestModelRepository->create($input);

        Flash::success('Request Model saved successfully.');

        return redirect(route('requestModels.index'));
    }

    /**
     * Display the specified RequestModel.
     *
     * @param int $id
     *
     * @return Response
     */
    public function show($id)
    {
        $requestModel = $this->requestModelRepository->find($id);

        if (empty($requestModel)) {
            Flash::error('Request Model not found');

            return redirect(route('requestModels.index'));
        }

        return view('request_models.show')->with('requestModel', $requestModel);
    }

    /**
     * Show the form for editing the specified RequestModel.
     *
     * @param int $id
     *
     * @return Response
     */
    public function edit($id)
    {
        $requestModel = $this->requestModelRepository->find($id);

        if (empty($requestModel)) {
            Flash::error('Request Model not found');

            return redirect(route('requestModels.index'));
        }

        return view('request_models.edit')->with('requestModel', $requestModel);
    }

    /**
     * Update the specified RequestModel in storage.
     *
     * @param int $id
     * @param UpdateRequestModelRequest $request
     *
     * @return Response
     */
    public function update($id, UpdateRequestModelRequest $request)
    {
        $requestModel = $this->requestModelRepository->find($id);

        if (empty($requestModel)) {
            Flash::error('Request Model not found');

            return redirect(route('requestModels.index'));
        }

        $requestModel = $this->requestModelRepository->update($request->all(), $id);

        Flash::success('Request Model updated successfully.');

        return redirect(route('requestModels.index'));
    }

    /**
     * Remove the specified RequestModel from storage.
     *
     * @param int $id
     *
     * @throws \Exception
     *
     * @return Response
     */
    public function destroy($id)
    {
        $requestModel = $this->requestModelRepository->find($id);

        if (empty($requestModel)) {
            Flash::error('Request Model not found');

            return redirect(route('requestModels.index'));
        }

        $this->requestModelRepository->delete($id);

        Flash::success('Request Model deleted successfully.');

        return redirect(route('requestModels.index'));
    }
}
