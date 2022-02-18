<?php

namespace App\Http\Controllers;

use App\Http\Requests\CreatePupilRequest;
use App\Http\Requests\UpdatePupilRequest;
use App\Repositories\PupilRepository;
use App\Http\Controllers\AppBaseController;
use Illuminate\Http\Request;
use Flash;
use Response;

class PupilController extends AppBaseController
{
    /** @var PupilRepository $pupilRepository*/
    private $pupilRepository;

    public function __construct(PupilRepository $pupilRepo)
    {
        $this->pupilRepository = $pupilRepo;
    }

    /**
     * Display a listing of the Pupil.
     *
     * @param Request $request
     *
     * @return Response
     */
    public function index(Request $request)
    {
        $pupils = $this->pupilRepository->all();

        return view('pupils.index')
            ->with('pupils', $pupils);
    }

    /**
     * Show the form for creating a new Pupil.
     *
     * @return Response
     */
    public function create()
    {
        return view('pupils.create');
    }

    /**
     * Store a newly created Pupil in storage.
     *
     * @param CreatePupilRequest $request
     *
     * @return Response
     */
    public function store(CreatePupilRequest $request)
    {
        $input = $request->all();

        $pupil = $this->pupilRepository->create($input);

        Flash::success('Pupil saved successfully.');

        return redirect(route('pupils.index'));
    }

    /**
     * Display the specified Pupil.
     *
     * @param int $id
     *
     * @return Response
     */
    public function show($id)
    {
        $pupil = $this->pupilRepository->find($id);

        if (empty($pupil)) {
            Flash::error('Pupil not found');

            return redirect(route('pupils.index'));
        }

        return view('pupils.show')->with('pupil', $pupil);
    }

    /**
     * Show the form for editing the specified Pupil.
     *
     * @param int $id
     *
     * @return Response
     */
    public function edit($id)
    {
        $pupil = $this->pupilRepository->find($id);

        if (empty($pupil)) {
            Flash::error('Pupil not found');

            return redirect(route('pupils.index'));
        }

        return view('pupils.edit')->with('pupil', $pupil);
    }

    /**
     * Update the specified Pupil in storage.
     *
     * @param int $id
     * @param UpdatePupilRequest $request
     *
     * @return Response
     */
    public function update($id, UpdatePupilRequest $request)
    {
        $pupil = $this->pupilRepository->find($id);

        if (empty($pupil)) {
            Flash::error('Pupil not found');

            return redirect(route('pupils.index'));
        }

        $pupil = $this->pupilRepository->update($request->all(), $id);

        Flash::success('Pupil updated successfully.');

        return redirect(route('pupils.index'));
    }

    /**
     * Remove the specified Pupil from storage.
     *
     * @param int $id
     *
     * @throws \Exception
     *
     * @return Response
     */
    public function destroy($id)
    {
        $pupil = $this->pupilRepository->find($id);

        if (empty($pupil)) {
            Flash::error('Pupil not found');

            return redirect(route('pupils.index'));
        }

        $this->pupilRepository->delete($id);

        Flash::success('Pupil deleted successfully.');

        return redirect(route('pupils.index'));
    }
}
